#include "5.6_ptr-funcs.h"

int strindex(char *s, char *t) {
    char *b = s;
    char *p, *r;

    while (*s++ != '\0') {
        for (p = s, r = t; *r != '\0' && *p == *r; p++, r++)
            ;

        if (r > t && *r == '\0')
            return s - b;
    }
    return -1;
}