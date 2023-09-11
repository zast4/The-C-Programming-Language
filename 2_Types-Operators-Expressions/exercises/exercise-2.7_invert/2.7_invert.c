/**
 *
 * Exercise 2.7
 *
 * Write a function invert(x,p,n) that returns x with n bit starting at p
 * inverted .
 *
 **/

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main() {
  printf("%d\n", invert(10, 2, 2));
  printf("%d\n", invert(255, 3, 4));
  printf("%d\n", invert(12, 3, 2));
  printf("%u\n", ~0);
  return 0;
}

unsigned invert(unsigned x, int p, int n) {
  unsigned RIGHT_N_1 = ~(~0 << n);
  unsigned BITS_TO_MOVE_FOR_MASK = p + 1 - n;
  unsigned MASK = RIGHT_N_1 << BITS_TO_MOVE_FOR_MASK;
  return (x & ~MASK) | (~x & MASK);  // or x ^ MASK
}