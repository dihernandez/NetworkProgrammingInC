#include "ip_maths.h"
#include "binary_ops.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <inttypes.h>


#define IP_NUM_BITS 32

static uint8_t string_to_int(char *str);
static uint32_t ip_to_int(char *ip_addr);
static void int_to_string(uint32_t addr, char *str_ip_addr);

void get_broadcast_address(char *ip_addr, char mask, char* output_buffer) {
  uint32_t int_ip = ip_to_int(ip_addr);
  uint32_t mask_bits = create_mask_32_complement(mask);
  uint32_t broadcast_address_bits = int_ip | mask_bits;
  int_to_string(broadcast_address_bits, output_buffer);
}

unsigned int get_ip_integral_equivalent(char *ip_address){
  return ip_to_int(ip_address);
}

static void int_to_string(uint32_t addr, char *str_ip_addr) {
  for(int i = 0; i < 4; i++) {
    uint32_t mask = BASE ^ ~(0xFFU << (INT32_SIZE - (i+1)*8));
    int num = (int)((addr&mask)>> (INT32_SIZE - (i+1)*8));
    char num_str[10];
    sprintf(num_str,"%d",num);
    strcat(str_ip_addr,num_str);
    if(i < 3) {
      char dot = '.';
      strncat(str_ip_addr,&dot,1);
    }
  }
}

static uint8_t string_to_int(char *str) {
  int num = atoi(str);
  if(num > 255 || num < 0) {
    perror("number not in range");
  }
  uint8_t result = (uint8_t)num;
  return result;
}

static uint32_t ip_to_int(char *ip_addr) {
  uint8_t octet[4];
  int i = 0;
  char *ip_addr_local = strdup(ip_addr);
  char *token = strtok(ip_addr_local, ".");
  while(token != NULL && i < 4) {
    octet[i++] = string_to_int(token);
    token = strtok(NULL,".");
  }
  uint32_t ip_int = 0;
  for(int i = 0; i < 4; i++) {
    uint8_t segment = octet[i];
    uint32_t to_add = (uint32_t)segment << (INT32_SIZE - ((i+1)*8));
    ip_int |= to_add;
  }
  return ip_int;
}
