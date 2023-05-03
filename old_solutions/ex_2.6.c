#include <stdio.h>
#include <limits.h>

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y);

int* dec2bin(int* bin, int x);

int main() {
    //int bin[32];
    //dec2bin(bin, 254);


    printf("setbits: %d\n", setbits(363, 4, 3, 373));
    return 0;
}

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y) {
    // Maximum number of positions to shift allowed, 2**n-1
    const unsigned max_shift = sizeof(unsigned) * CHAR_BIT - 1;
    //printf("%u", max_shift);
    // Mask, not shifted
    const unsigned mask = n != max_shift ? (1 << (n & max_shift)) - 1 : -1;
    printf("%u\n", 2 << -1);
    return (x & ~(mask << p)) | ((y & mask) << p);
}
