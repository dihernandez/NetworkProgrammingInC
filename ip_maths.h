#ifndef __IP_MATHS_H
#define __IP_MATHS_H
#include "binary_ops.h"

void get_broadcast_address(char *ip_addr, char mask, char* output_buffer);
unsigned int get_ip_integral_equivalent(char *ip_address);

#endif // __IP_MATHS_H
