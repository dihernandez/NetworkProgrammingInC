#ifndef __BINARY_OPS_H
#define __BINARY_OPS_H
#include "stdint.h"
#define INT32_SIZE 32
#define BASE 0xFFFFFFFF

void print_binary(uint32_t n);
uint32_t create_mask_32(char mask);
uint32_t create_mask_32_complement(char mask);
#endif /*__BINARY_OPS_H*/
