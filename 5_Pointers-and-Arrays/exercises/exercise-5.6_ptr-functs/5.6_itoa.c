#include "5.6_ptr-funcs.h"

void itoa_v2(int n, char *s) {
    int sign;
    char *t = s;
    if ((sign = n) < 0)
        n = -n;
    
    do {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(t);
}