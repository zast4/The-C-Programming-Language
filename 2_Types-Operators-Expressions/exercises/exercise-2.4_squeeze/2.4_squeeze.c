#include <stdio.h>

/**
 * Exercise 2.4 - Write a version of squeeze(s1,s2) that deletes each
 * character in the string 1 that matches any character in the string s2
 *
 */

#define MAXLINE 100

#define YES 1
#define NO 0

int mgetline(char line[], int lim);
void squeeze(char s1[], char s2[]);

int main() {
    char line[MAXLINE];

    mgetline(line, MAXLINE);
    squeeze(line, "abz");

    printf("The result string %s\n", line);
    return 0;
}

void squeeze(char s1[], char s2[]) {
    int i, j, k;
    k = 0;

    for (i = 0; s1[i] != '\0'; ++i) {
        for (j = 0; (s1[i] != s2[j]) && s2[j] != '\0'; ++j);
        if (s2[j] == '\0')
            s1[k++] = s1[i];
    }
    s1[k] = '\0';
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