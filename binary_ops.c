#include "binary_ops.h"
#include "stdio.h"

void print_binary(uint32_t n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

uint32_t create_mask_32(char mask) {
  uint32_t mask_low_bits = BASE >> ((uint8_t)mask);
  uint32_t mask_32_bits = BASE&~mask_low_bits;
  return mask_32_bits;
}

uint32_t create_mask_32_complement(char mask) {
  uint32_t complement =  BASE >> ((uint8_t)mask);
  return complement;
}
