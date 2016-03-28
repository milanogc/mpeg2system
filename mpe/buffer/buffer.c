#include <stdio.h>		/* standard headers */
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include <sys/types.h>		/* inet funcs */
#include <sys/socket.h>
#include <arpa/inet.h>

#include <netinet/in_systm.h>	/* network headers */
#include <netinet/in.h>
#include <netinet/ip.h>
#include <net/if.h>
#include <net/ethernet.h>

#include <pcap.h>		/* libpcap */

#include <pthread.h>

#include "error.h"
#include "buffer.h"
#include "hash.h"
#include "multi.h"

/* our stop function has to know the tid in order
   to stop the thread. */
static pthread_t buffer_tid;

/* muttex to control read/write in the buffer */
static pthread_mutex_t buffer_mutex = PTHREAD_MUTEX_INITIALIZER;

/* these variables are defined in the buffer.conf config
   file. */
static char *device;		/* device we should listen to */
static char *filter;		/* pcap command to compile */
static unsigned buffer_size;    /* size of the buffer */

/* max size of a packet: 4080 + sizeof(ether_header) */
#define MAX_PKT_SIZE 4094

/* other static variables */
static pcap_t *pd;

/* our local functions */
static void open_pcap(void);
static void *buffer_thread(void *arg);
static void read_config(void);
static char *readline(FILE *f);
static char *next_pcap(int *len);
static unsigned char *str2mac(char *);

/* return new buffer.  Just allocs memory and initialize the fields. */
buffer_t *
buffer_new(void)
{
  buffer_t *b;

  b = calloc(1, sizeof(buffer_t));
  if (b == NULL)
    return NULL;

  /* read the config file */
  read_config();

  /* init the packet buffer */
  b->buffer_size = buffer_size;
  b->packets = (packet_t *) calloc(b->buffer_size, sizeof(packet_t));

  return b;
}

/* release memory alloced by b */
void
buffer_free(buffer_t *b)
{
  free(b->packets);
  free(b);
}

/* initialize the packet capture. */
void
buffer_init_capture(buffer_t *b)
{
  pthread_create(&buffer_tid, NULL, buffer_thread, (void *) b);
}

/* stops the packet capture. */
void
buffer_stop_capture(buffer_t *b)
{
  pthread_detach(buffer_tid);
  pcap_close(pd);
}

/* Return a pointer to the first packet in the queue. */
packet_t *
buffer_get_packet(buffer_t *b)
{
  packet_t *ret = NULL;
  static packet_t pkt;
  packet_t *pkt_ptr;

  pkt_ptr = &pkt;

  pthread_mutex_lock(&buffer_mutex);
  if (! buffer_is_empty(b))
    {
      memcpy(pkt_ptr, &(b->packets[b->out_pos]), sizeof(packet_t));

      b->out_pos = (b->out_pos+1)%(b->buffer_size);

      ret = pkt_ptr;
    }
  pthread_mutex_unlock(&buffer_mutex);

  return ret;
}

/* tests wether b is empty */
int
buffer_is_empty(buffer_t *b)
{
  return b->out_pos == b->in_pos;
}

/* tests wether b is full */
int
buffer_is_full(buffer_t *b)
{
  int tmp;

  tmp = (b->in_pos+1)%(b->buffer_size);

  return tmp == b->out_pos;
}

/* read a line from f. returns the line without the leading '\n' */
static char *
readline(FILE *f)
{
  char line[1024];

  if ( (fgets(line, 1024, f)) == NULL)
    return NULL;

  line[strlen(line)-1] = '\0';
  if (line[strlen(line)-1] == '\r')
    line[strlen(line)-1] = '\0';

  return strdup(line);
}

/* read the config file, located at /etc/buffer.conf */
static void
read_config(void)
{
  char *id, *arg;
  FILE *f;

  f = fopen("/etc/buffer.conf", "r");
  if (f == NULL)
    err_sys("read_config");

  while ( (id = readline(f)) != NULL)
    {
      if (isspace(*id) || *id == '#')
	{
	  free(id);
	  continue;
	}

      arg = strchr(id, '=');
      if (arg == NULL) /* do nothing */
	do {} while (0);
      else
	*arg++ = '\0';

      if (strcasecmp(id, "FILTER") == 0)
	{
	  filter = strdup(arg);
	}
      else if (strcasecmp(id, "DEVICE") == 0)
	{
	  device = strdup(arg);
	}
      else if (strcasecmp(id, "BUFFER_SIZE") == 0)
	{
	  buffer_size = strtoul(arg, NULL, 10);
	  if (buffer_size == ULONG_MAX)
	    buffer_size = 0;	/* wrong parameter */
	}

      free(id);
    }

  if (device == NULL || filter == NULL || buffer_size == 0)
    err_msg("something missing while reading the config file\n");
  else
    print_deb(__DEBUG__, "device: %s, filter: %s, buffer_size: %u\n",
	      device, filter, buffer_size);

  fclose(f);
}

/* sets the filter and opens the pcap capture device. */
static void
open_pcap(void)
{
  uint32_t localnet, netmask;
  char errbuf[PCAP_ERRBUF_SIZE];
  char str1[INET_ADDRSTRLEN], str2[INET_ADDRSTRLEN];
  struct bpf_program fcode;

  pd = pcap_open_live(device, MAX_PKT_SIZE, 0, 500, errbuf);
  if (pd == NULL)
    err_quit("pcap_open_live: %s\n", errbuf);

  if (pcap_lookupnet(device, &localnet, &netmask, errbuf) < 0)
    err_quit("pcap_lookupnet: %s\n", errbuf);

  print_deb(__DEBUG__, "localnet = %s, netmask = %s\n",
	    inet_ntop(AF_INET, &localnet, str1, sizeof(str1)),
	    inet_ntop(AF_INET, &netmask, str2, sizeof(str2)));

  print_deb(__DEBUG__, "compiling %s\n", filter);
  if (pcap_compile(pd, &fcode, filter, 0, netmask) < 0)
    err_quit("error while trying to compile %s, %s\n", 
	     filter, pcap_geterr(pd));

  if (pcap_setfilter(pd, &fcode) < 0)
    err_quit("pcap_setfilter: %s\n", pcap_geterr(pd));
}

/* get next packet that matches the filter */
static char *
next_pcap(int *len)
{
  char *ptr;
  struct pcap_pkthdr hdr;

  /* keep looping until packet ready */
  while ( (ptr = (char *) pcap_next(pd, &hdr)) == NULL)
    ;

  *len = hdr.caplen;		/* captured length. */
  return ptr;
}

/* thread that reads the packets and stores them in our buffer. */
static void *
buffer_thread(void *arg)
{
  int len;
  char *ptr, *mac_ptr, ip[256];
  unsigned char *mac;
  struct ether_header *eptr;
  struct ip *ip_hdr;

  packet_t *pkt_ptr;
  mac_table_t *t;

  buffer_t *b = (buffer_t *) arg;

  t = mac_table_new();
  if (t == NULL)
    err_quit("error initializing the mac_table\n");

  if (mac_table_read_file(t, "/etc/buffer.conf") == -1)
    err_quit("error while reading /etc/buffer.conf\n");

  open_pcap();

  for (;;)
    {
      ptr = next_pcap(&len);

      eptr = (struct ether_header *) ptr;
      if (ntohs(eptr->ether_type) != ETHERTYPE_IP)
	print_deb(__DEBUG__, "Ethernet type %x not IP\n", ntohs(eptr->ether_type));

      pthread_mutex_lock(&buffer_mutex);
      if (! buffer_is_full(b))
	{
	  pkt_ptr = &(b->packets[b->in_pos]);

	  /* test if the packet is bigger than we want 
	     len = ether(14) + ip(20) + payload(the rest)
	     the app just wants ip and the payload */
	  if (len > MAX_PKT_SIZE)
	    {
	      err_msg("packet length (%u) is bigger than the maximum defined (%u)\n",
		      len, MAX_PKT_SIZE);
	      pkt_ptr->length = MAX_PKT_SIZE - 14;
	    }
	  else
	    {
	      pkt_ptr->length = len - 14;
	    }

	  /* copy the payload int pkt_ptr->data.
	     ptr+14 points to the ip header. */
	  memcpy(pkt_ptr->data, ptr+14, pkt_ptr->length);

	  /* check if ip is multicast */
	  ip_hdr = (struct ip *) pkt_ptr->data;
	  inet_ntop(AF_INET, &ip_hdr->ip_dst, ip, 256);

	  printf("* pkt_ptr: %p addr: %s\n", ip_hdr, ip);

	  if (! is_multicast(*(unsigned *) &ip_hdr->ip_dst))
	    {
	      mac_ptr = mac_table_lookup(t, ip);
	      if (mac_ptr == NULL)
		{
		  err_msg("* ip (%s) isnt multicast, mac not found!\n",
			  ip);
		  memset(pkt_ptr->mac, 0, 6);
		}
	      else
		{
		  mac = str2mac(mac_ptr);
			 
		  memcpy(pkt_ptr->mac, mac, 6);
		}
	    }
	  else
	    {
	      memcpy(pkt_ptr->mac, eptr->ether_dhost, 6);
	    }



	  b->in_pos = (b->in_pos+1)%(b->buffer_size);
	}
      pthread_mutex_unlock(&buffer_mutex);
    }

  return NULL;
}

static unsigned char _mac_buf[6];

static unsigned char *
str2mac(char *mac_ptr)
{
  char *delim = ":";
  char *p;
  int i;

  i = 0;
  p = strtok(mac_ptr, delim);
  do
    {
      _mac_buf[i] = (unsigned char) strtol(p, NULL, 16);
    }
  while (++i < 6 && (p = strtok(NULL, delim)));

  return _mac_buf;
}
