#include <stdio.h>
#include <limits.h>

unsigned invert(unsigned x, unsigned p, unsigned n);

int main() {

    printf("invert: %u\n", invert(373, 5, 4));
    return 0;
}

//unsigned invert(unsigned x, unsigned p, unsigned n) {
//    const unsigned mask = ~(-1 << (p + 1) | (x & ((1 << (p + 1)) - 1))) ;
//    const unsigned left_side = x & (-1 << (p + 1));
//    printf("%u\n", mask);
//    printf("%u\n", left_side);
//    return left_side | mask;
//    const unsigned max_shift = sizeof(unsigned) * CHAR_BIT - 1;
//    const unsigned mask = (1 << n) - 1;
//    return (x & ~(mask << p)) | ((y & mask) << p);
//}

unsigned invert(unsigned x, unsigned p, unsigned n) {
    const unsigned mask = (-1 << (p + 1)) | (~(-1 << (p - n + 1)));
    const unsigned inverted = ~(mask | x);
    const unsigned right = x & ~(-1 << (p - n + 1));
    const unsigned left = x & (-1 << (p + 1));
    return right | inverted | left;
}