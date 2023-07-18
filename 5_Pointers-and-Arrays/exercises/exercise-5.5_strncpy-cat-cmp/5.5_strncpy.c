#include "5.5_strn.h"

/* copy at most n characters of string ct to s; return s. Pad with '\0'
if ct has fewer than n characters. */
void strn_cpy(char *s1, char *s2, int n) {
    while (*s1++);
    s1--;
    while (n-- > 0 && (*s1++ = *s2++));
    if (n > 0)
        *s1++;
    *s1 = '\0';
}

