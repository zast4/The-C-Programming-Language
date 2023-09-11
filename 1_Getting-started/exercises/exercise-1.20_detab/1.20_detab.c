/**
 * Exercise 1.20 -
 *
 * Write a Program detab, which replaces tabs in the input with a proper
 * number of blanks to spaces
 *
 **/

#include <stdio.h>

#define MAXLENGTH 1000
#define TABSIZE 8

void detab(char s[], int len);
int get_line(char s[], int lim);

int main() {
    char line[MAXLENGTH];
    int len;
    do {
        len = get_line(line, MAXLENGTH);
        detab(line, len);
    }
    while (line[len - 1] != EOF);
    return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i++] = c;
    }
    else if (c == EOF) {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

void detab(char s[], int len) {
    int nonTabCount = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '\t') {
            while (TABSIZE - nonTabCount > 0) {
                putchar(' ');
                nonTabCount++;
            }
            nonTabCount = 0;
        } else {
            putchar(s[i]);
            nonTabCount++;
            if (nonTabCount >= TABSIZE)
                nonTabCount = 0;
        }
    }
}