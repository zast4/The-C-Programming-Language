#include <stdio.h>

/* 
 * Exercise 2.9
 * In twos complement number systems, x &= (x-1) deletes the rightmost 1 bit in
 * x. Explain why? Use this to right a faster version of bitcount. Bitcount
 * program counts the number of 1 bits in the integer */

/* int bitcount: count 1 bits in x */
int bitcount(unsigned x);

int main() { 
  printf("%d", bitcount(0));
  return 0;
}

int bitcount(unsigned x) {
  int i;
  for (i = 0; x != 0; x &= (x - 1), ++i);
  return i;
}