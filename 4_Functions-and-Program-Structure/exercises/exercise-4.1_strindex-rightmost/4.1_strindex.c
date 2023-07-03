#include <stdio.h>
#define MAXLINE 1000

int strindex(char s[], char t[]);
int get_line(char s[], int lim);

char pattern[] = "ould";

int main() {
    char line[MAXLINE];
    while (get_line(line, MAXLINE) != 0) {
        printf("%d\n", strindex(line, pattern));
    }
    return 0;
}

/* getline: get line into s, return length */
int get_line(char s[], int lim) {
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[]) {
    int i, j, k, position = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            position = i;
    }
    return position;
}