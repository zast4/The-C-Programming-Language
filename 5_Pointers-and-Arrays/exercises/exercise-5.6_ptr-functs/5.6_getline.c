#include "5.6_ptr-funcs.h"

int get_line(char *s, int lim) {
    int c;
    char *t = s;
    while ((c = getchar()) != EOF && --lim > 0 && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return t - s;
}