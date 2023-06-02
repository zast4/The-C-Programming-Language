#include <stdio.h>

#define MAXLENGTH 1000

void reverse(char s[], int length);
int get_line(char s[], int lim);

int main() {
    char line[MAXLENGTH];
    int len;
    do {
        len = get_line(line, MAXLENGTH);
        reverse(line, len);
        printf("%s", line);
    }
    while (line[len - 1] != EOF);
    return 0;
}

void reverse(char s[], int length) {
    char tmp;
    int i, j;
    for (i = 0, j = length - 2; i < j; ++i, --j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
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