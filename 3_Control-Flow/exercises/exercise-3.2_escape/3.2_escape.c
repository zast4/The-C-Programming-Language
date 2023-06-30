#include <stdio.h>
#define MAXLINE 1000

void escape(char s[], char t[]);
int get_line(char s[], int lim);

int main () {
    char s[MAXLINE], t[MAXLINE];
    get_line(t, MAXLINE);
    escape(s, t);
    printf("%s", s);
    return 0;
}

void escape(char s[], char t[]) {
    int i = 0;
    int j = 0;
    while (t[i] != '\0') {
        switch (t[i]) {
            case '\n':
                s[j] = '\\';
                j++;
                s[j] = 'n';
                break;
            case '\t':
                s[j] = '\\';
                j++;
                s[j] = 't';
                break;
            default:
                s[j] = t[i];
                break;
        }
        j++;
        i++;
    }
    s[j] = '\0';
}

int get_line(char s[], int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i)
        s[i] = c;

    s[i] = '\0';
}