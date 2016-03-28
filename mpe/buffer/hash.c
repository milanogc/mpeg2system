#include <glib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "hash.h"

mac_table_t *
mac_table_new(void)
{
  mac_table_t *t;

  t = g_hash_table_new(g_str_hash, g_str_equal);

  return t;
}

int
mac_table_insert(mac_table_t *t, char *ip, char *mac)
{
  g_hash_table_insert(t, (gpointer) ip, (gpointer) mac);

  return 0;
}

int
mac_table_delete(mac_table_t *t, char *ip)
{
  g_hash_table_remove(t, (gpointer) ip);

  return 0;
}

char *
mac_table_lookup(mac_table_t *t, char *ip)
{
  return (char *) g_hash_table_lookup(t, (gpointer) ip);
}

void
mac_table_free(mac_table_t *t)
{
  g_hash_table_destroy(t);
}

int
mac_table_read_file(mac_table_t *t, char *filename)
{
  FILE *fp;
  char line[1024], ip[256], mac[256];
  int i;

  fp = fopen(filename, "r");
  if (fp == NULL)
    {
      perror ("mac_table_read_file, fopen");
      return -1;
    }

  while (fgets(line, 1023, fp))
    {
      /* skip white-spaces */
      for (i = 0; line[i] && isspace(line[i]); ++i)
	;

      /* ignore blank and comments */
      if (line[i] == '\0' || line[i] == '#')
	continue;

      /* get the ip address and mac from file
	 anything that does not match MAC=ip mac will
	 hopelly be ignored */
      if (sscanf(line+i, "MAC=%256s %256s", ip, mac) == 2)
	mac_table_insert(t, strdup(ip), strdup(mac));
    }

  return 0;
}

#if 0				/* set to 1 if you want to test */

void
func(gpointer ip,
     gpointer mac,
     gpointer null)
{
  printf("%s %s\n", (char *) ip, (char *) mac);
}

int
mac_table_print(mac_table_t *t)
{
  g_hash_table_foreach(t, func, NULL);

  return 0;
}

int
main(void)
{
  mac_table_t *t;

  t = mac_table_new();

  mac_table_read_file(t, "/etc/buffer.conf");

  mac_table_print(t);

  return 0;
}
#endif
