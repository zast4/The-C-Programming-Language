#include <stdio.h>

/**
 * Exercise 2.3 - htoi program, character to integer program.
 *
 */

#define MAXLINE 100

#define YES 1
#define NO 0

int mgetline(char line[], int lim);

int htoi(char s[]);

int main() {
    char line[MAXLINE];
    int value;

    mgetline(line, MAXLINE);
    value = htoi(line);

    printf("The value of %s is %d\n", line, value);
    return 0;
}

int htoi(char s[]) {
    int hexdigit, i, inhex, n;
    i = 0;
    if (s[i] == '0') {
        ++i;
        if (s[i] == 'x' || s[i] == 'X')
            ++i;
    }
    n = 0;
    inhex = YES;
    for (; inhex == YES; ++i) {
        if (s[i] >= '0' && s[i] <= '9')
            hexdigit = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'z')
            hexdigit = s[i] - 'a' + 10;  // That is how we get the value of hexadecimal number in decimal number system
        else if (s[i] >= 'A' && s[i] <= 'Z')
            hexdigit = s[i] - 'A' + 10;
        else
            inhex = NO;

        if (inhex == YES)
            n = n * 16 + hexdigit;
    }
    return n;
}

int mgetline(char line[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}