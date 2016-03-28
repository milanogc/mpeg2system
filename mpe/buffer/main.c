#include <stdio.h>
#include <unistd.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <arpa/inet.h>

#include "error.h"
#include "buffer.h"

/* This main file is used for tests only. */

int
main(void)
{
  buffer_t *b;
  packet_t *pkt_ptr;
  unsigned i = 0;
  struct ip *ip_hdr;
  char ip1[256], ip2[256];

  b = buffer_new();

  buffer_init_capture(b);
  for ( ; ; )
    {
      /* pkt_ptr->data points to the ip header of the packet */
      while ( (pkt_ptr = buffer_get_packet(b)) == NULL)
	;

      printf("Packet: %d\n", ++i);
      printf("\tmac: %02X:%02X:%02X:%02X:%02X:%02X\n",
	     ((unsigned)pkt_ptr->mac[0])%0x100, 
	     ((unsigned)pkt_ptr->mac[1])%0x100, 
	     ((unsigned)pkt_ptr->mac[2])%0x100,
	     ((unsigned)pkt_ptr->mac[3])%0x100, 
	     ((unsigned)pkt_ptr->mac[4])%0x100, 
	     ((unsigned)pkt_ptr->mac[5])%0x100);
      printf("\tlength: %d\n", pkt_ptr->length);

      ip_hdr = (struct ip *) pkt_ptr->data;
      printf("* IP info: header_len: %u saddr: %s daddr: %s\n",
	     ip_hdr->ip_hl,
	     inet_ntop(AF_INET, &ip_hdr->ip_src, ip1, 256),
	     inet_ntop(AF_INET, &ip_hdr->ip_dst, ip2, 256));
    }
  buffer_stop_capture(b);
  buffer_free(b);

  return 0;
}
