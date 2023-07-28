#include "5.6_ptr-funcs.h"

#define NUMBER '0'

int getop(char *s) {
    int c;

    while ((*s = c = getchar()) == ' ' || c == '\t');  // Skip white spaces

    *(s + 1) = '\0';

    if (!isdigit(c) && c != '.')
        return c;  // 1. Not a number
    if (isdigit(c))
        while (isdigit(*++s = c = getchar()));
    
    if (c == '.')
        while (isdigit(*++s = c = getchar()));
    
    *s = '\0';

    if (c != EOF)
        ungetc(c, stdin);
    return NUMBER;
}