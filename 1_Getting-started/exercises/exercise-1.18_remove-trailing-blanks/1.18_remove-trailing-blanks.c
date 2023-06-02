#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
void remove_trailing_blanks(char line[], int len);

/* print line without trailing blanks */

int main() {
    char line[MAXLINE];  // current input line
    int len;  
    do {
        len = get_line(line, MAXLINE);  // get a new line and set a length value
        remove_trailing_blanks(line, len);
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

void remove_trailing_blanks(char line[], int len) {
    if (line[len - 1] == EOF)  // if the last read symbol is EOF we put \n for beautiful output
            putchar('\n');
    for (int i = 2; line[len - i] == ' ' || line[len - i] == '\t'; ++i) {  // if one of the last read symbols is ' ' or '\t' we replace it with '\0'
        line[len - i] = '\0';
    }
    for (int i = 0; i < len; ++i) {
        if (line[i] == ' ' || line[i] == '\t')  // if ' ' or '\t' is not in the end we replace it with square bracket
            putchar('[');  // Square bracket to display blanks in terminal and check that there is no of them in the end
        else
            putchar(line[i]);
    }
}

