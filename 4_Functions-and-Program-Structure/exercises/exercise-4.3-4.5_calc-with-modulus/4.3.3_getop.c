#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "funcitons.h"

/* getop: get next character or numeric operand */
int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    i = 0;
    if (islower(c)) {
        while (islower(s[++i] = c = getch()));
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        if (strlen(s) > 1)
            return NAME;
        else
            return s[0];
    }

    if (!isdigit(c) && c != '.' && c != '-')
        return c;  /* not a number */
    if (c == '-' || isdigit(c)) /* collect integer part along with - */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')  /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    if (strcmp(s, "-") == 0)
        return '-';
    return NUMBER;
}
