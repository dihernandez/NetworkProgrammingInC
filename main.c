#include "ip_maths.h"
#include <string.h>
#include <stdio.h>

#define PREFIX_LEN 16

int main(){
  char ipadd_buffer[PREFIX_LEN];
  memset(ipadd_buffer,0,PREFIX_LEN);
  char *ip_add = "192.168.2.10";
  char mask = 20;
  get_broadcast_address(ip_add,mask,ipadd_buffer);
  printf("Broadcast address = %s\n", ipadd_buffer); // expect = 192.168.15.255

  char *ip_address = "192.168.0.10";
  unsigned int int_ip = get_ip_integral_equivalent(ip_address);
  printf("Integer equivalent for %s is %u\n", ip_address, int_ip); // expect = 3232235530
  return 0;
}
