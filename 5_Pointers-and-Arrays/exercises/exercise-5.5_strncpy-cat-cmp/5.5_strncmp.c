#include "5.5_strn.h"

int strn_cmp(char *s1, char *s2, int n) {
    while (n-- > 0 && (*s1++ == *s2++));
    if (n == 0)
        return 0;
    else
        return *s1 - *s2;
}