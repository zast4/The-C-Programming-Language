#include <stdio.h>
#include <string.h>

void reverse(char s[]);
int get_line(char line[], int lim);

int main() {

    return 0;
}

void reverse(char s[]) {
    static int i = 0;
    static int len;

    int j;
    int c;

    if (i == 0) {
        len = strlen(s);
    }

    j = len - (i + 1);

    if (i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        i++;
        reverse(s);
    }

    else {
        i = 0;
    }
}

int get_line(char line[], int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n')
        line[i++] = '\n';

    line[i] = '\0';
}