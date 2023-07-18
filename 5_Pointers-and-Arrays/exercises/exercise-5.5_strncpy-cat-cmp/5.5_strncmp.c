#include "5.5_strn.h"

/* compare at most n characters of string cs to string ct; return <0 if cs<ct, 0 if cs==ct, or >0 if cs>ct. */
int strn_cmp(char *s1, char *s2, int n) {
    while (n-- > 0 && (*s1++ == *s2++));
    if (n == 0)
        return 0;
    else
        return *s1 - *s2;
}