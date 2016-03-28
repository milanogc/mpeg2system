#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>

#include "multi.h"

int
is_multicast(unsigned addr)
{
  /* if the first 3 bits of addr are 1s than ip is multicast */
  return (0xE0 & addr) == 0xE0;
}
