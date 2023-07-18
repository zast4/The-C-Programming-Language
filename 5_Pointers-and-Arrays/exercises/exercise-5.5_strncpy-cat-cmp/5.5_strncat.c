#include "5.5_strn.h"

char* strn_cat(char *s1, char *s2, int n) {
    while (*s1++);
    s1--;
    while (n-- > 0 && (*s1++ = *s2++));
    *s1 = '\0';
    return s1;
}