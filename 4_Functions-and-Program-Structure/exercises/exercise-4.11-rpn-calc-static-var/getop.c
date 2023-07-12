#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include "calc.h"

#define MAXLINE 1000

int li = 0;  /* input line index */
char line[MAXLINE];  /* one input line */

/* getop: get next character or numeric operand */
int getop(char s[]) {
    int i, c;
    static int lastc = 0;

    if (lastc == 0)
        c = getch();
    else {
        c = lastc;
        lastc = 0;
    }

    while ((s[0] = c) == ' ' || c == '\t')
        c = getch();

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;

    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()));
    if (c == '.')
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';

    if (c != EOF)
        lastc = c;

    return NUMBER;
}

/* mathfnc: check the string s for supported math function */

void mathfnc(char s[]) {
    double op2;

    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
    }
    else
        printf("error: %s is not supported\n", s);
}

