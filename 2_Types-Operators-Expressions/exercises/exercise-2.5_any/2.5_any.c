#include <stdio.h>

/**
 * Exercise 2.5
 *
 * Write the function any(s1,s2) which returns the first location in the string
 * s1 where any character from the string s2 occurs, or -1 if s1 contains
 * no characters from s2. ( The standard library function strpbrk does
 * the same job but returns a pointer to the location
 *
 **/

#define MAXLINE 100

#define YES 1
#define NO 0

int mgetline(char line[], int lim);
int any(char s1[], char s2[]);

int main() {
    char line[MAXLINE];

    mgetline(line, MAXLINE);
    int result = any(line, "abz");

    printf("The result %c\n", result);
    return 0;
}

int any(char s1[], char s2[]) {
    int i, j;
    for (i = 0; s1[i] != '\0'; ++i) {
        for (j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j] && s2[j] != '\n')
                return s1[i];
        }
    }
    return -1;
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