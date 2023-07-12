#include "funcitons.h"

#define BUFSIZE 100


// note for Exercise 4-8. If there will never be more than one character of pushback, just replace buf array with buf char variable
int buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void) {  /* get a (possibly pushed-back) characher */
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {  /* push character back on input */
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[]) {
    int i;
    i = strlen(s);
    while (i > 0)
        ungetch(s[--i]);
}