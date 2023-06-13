#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
  printf("%d\n", setbits(255, 3, 4, 0));
  printf("%d\n", setbits(12, 3, 2, 57));
  return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  unsigned RIGHT_N_1 = ~(~0 << n);  // Get rightmost ones equal to the n bits we need to replace
  unsigned BITS_TO_MOVE_FOR_MASK = p + 1 - n;  // This var is needed to shift previous value (RIGHT_N_1) so that it matches the location of the bits we need to replace in x 
  unsigned MASK = RIGHT_N_1 << BITS_TO_MOVE_FOR_MASK;  // This mask in 15 line is used to ing needed bits in x to 0 and ing everything except these bits to 0 in y. So bits we need in mask are 1
  return x & ~MASK | (y & MASK);
}