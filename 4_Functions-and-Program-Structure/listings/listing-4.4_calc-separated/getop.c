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

    if (line[li] == '\0') {
        if (get_line(line, MAXLINE) == 0)
            return EOF;
        else 
            li = 0;
    }
    
    while ((s[0] = c = line[li++]) == ' ' || c == '\t');

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;  // 1. Any char that is not a digit and '.'
    
    i = 0;

    if (isdigit(c))
        while (isdigit(s[++i] = c = line[li++]));
    if (c == '.')
        while (isdigit(s[++i] = c = line[li++]));
    
    s[i] = '\0';
    li--;

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

