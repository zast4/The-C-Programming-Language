/* The source file numcmp.c */

#include "funcs.h"

#define MAXSTR 100

/* numcmp: compare s1 and s2 numerically */

int numcmp(char *s1, char *s2) {
    double v1, v2;
    char str[MAXSTR];

    substr(s1, str, MAXSTR);
    v1 = atof(str);

    substr(s2, str, MAXSTR);
    v2 = atof(str);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}