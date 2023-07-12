#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}