#include <stdio.h>
#include <limits.h>

unsigned rightrot(unsigned x, unsigned n);

int main() {
    printf("rightrot: %u\n", rightrot(16, 5));
    return 0;
}

unsigned rightrot(unsigned x, unsigned n) {
    unsigned max_shift = 1 << n;
    for (int i = 1; i <= (n & 31); ++i) {
        x >>= 1;
    }
    return x;
}