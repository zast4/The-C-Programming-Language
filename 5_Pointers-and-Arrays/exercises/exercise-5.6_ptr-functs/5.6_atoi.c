#include "5.6_ptr-funcs.h"

int atoi_v2(char *s) {
    int res, sign;
    for (; isspace(*s); s++)
        ;
    sign = (*s == '-') ? -1 : 1;

    if (*s == '+' || *s == '-')
        s++;
    for (res = 0; isdigit(*s); s++)
        res = 10 * res + *s - '0';
    return sign * res;
}