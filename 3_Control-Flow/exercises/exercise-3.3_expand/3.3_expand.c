#include <stdio.h>

#define MAXLINE 100

int get_line(char s[], int lim);
void expand(char s1[], char s2[]);

int main() {
    char s1[MAXLINE], s2[MAXLINE];
    get_line(s1, MAXLINE);
    expand(s1, s2);
    printf("%s", s2);
    return 0;
}

void expand(char s1[], char s2[]) {
    int i = 0, j = 0, c;
    while ((c = s1[i++]) != '\0') {
        if (s1[i] == '-' && c < s1[i + 1]) {
            i++;
            while (c < s1[i])
                s2[j++] = c++;
        }
        else {
            s2[j++] = c;
        }
    }
    s2[j] = '\0';
}

int get_line(char s[], int lim) {
    char c;
    int i;
    for (i = 0; i != lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
}
