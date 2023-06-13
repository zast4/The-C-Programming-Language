#include <stdio.h>

/* write a function rightrot(x,n) that returns the value of the integer x
 * rotated to rightby n bit positions */

unsigned rightrot(unsigned x, int n);
int wordlength(void);

int main() {
  printf("%u", (unsigned)rightrot((unsigned)1, (int)2));
  return 0;
}

unsigned rightrot(unsigned x, int n) {
  unsigned rbit;
  rbit = x << (wordlength() - n);
  x = x >> n;
  x = x | rbit;
  return x;
}

int wordlength(void) {
    int i;
    unsigned v = (unsigned)~0;
    for (i = 1; (v = v >> 1) > 0; i++);
    return i;
}