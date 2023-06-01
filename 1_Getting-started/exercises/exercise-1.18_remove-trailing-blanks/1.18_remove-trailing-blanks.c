#include <stdio.h>
#include <limits.h>
#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print line without trailing blanks */

int main() {
    char line[MAXLINE];  // current input line
    int len;
    while (line[(len = get_line(line, MAXLINE)) - 2] != EOF) {  // Get length of a line and immediately use this value to get the last symbol and check whather it is EOF
        for (int i = 2; line[len - i] == ' ' || line[len - i] == '\t'; ++i) {
            line[len - i] = '\0';
        }
        for (int i = 0; i < len; ++i) {
            if (line[i] == ' ' || line[i] == '\t')
                putchar('[');  // Square bracket to display trailing blanks in VsCode terminal
            else
                putchar(line[i]);
        }
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