/**
 *
 * Exercise 1.17 -  Program to print the length of all input lines greater
 * than 80 characters.
 *
 **/

#include <stdio.h>
#include <limits.h>
#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */

int main() {
    char line[MAXLINE];  // current input line
    int len = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > 80) {
            printf("%s", line);
        }
    return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}