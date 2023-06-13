#include <stdio.h>

/**
 *
 * Exercise 2.6 -  Write a function setbits(x,p,n,y) that returns x with the
 * n bits that begin at position p set to the rightmost n bits of y,leaving
 * the other bits unchanged.
 **/

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void) { 
    printf("%u\n", setbits((unsigned) 255, 3, 4, (unsigned) 0)); 
    printf("%u", setbits((unsigned) 12, 3, 2, (unsigned) 57)); 
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned RIGHT_N_1 = ~(~0 << n);  // x = 255; n = 4; p = 3; value = 1111 1111 -> 1111 0000 -> 0000 1111  |||  x = 12; p = 3; n = 2; 1111 1111 -> 1111 1100 -> 0000 0011
    unsigned BITS_TO_MOVE_FOR_MASK = p + 1 - n; // x = 255; n = 4; p = 3; value = 3 + 1 - 4 = 0  ||| x = 12, p = 3; n = 2,  value = 3 + 1 - 2 = 2; 0000 0011 << 2 -> 0000 1100
    return x & ~(RIGHT_N_1 << BITS_TO_MOVE_FOR_MASK) | (y & (RIGHT_N_1 << BITS_TO_MOVE_FOR_MASK));
}