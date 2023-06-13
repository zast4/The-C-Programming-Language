#include <stdio.h>

/* getbits: get n bits from position p */

unsigned getbits(unsigned x, int p, int n);

int main() {
  printf("%d\n", getbits(10, 3, 4));
  return 0;
}

unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p + 1 - n)) & ~(~0 << n);
}