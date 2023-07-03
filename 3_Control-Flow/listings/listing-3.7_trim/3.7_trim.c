#include <stdio.h> 
#include <ctype.h>
#include <string.h>

int trim(char s[]);

int main() {
    char s[] = "       ";
    trim(s);
    printf("%s", s);
    return 0;
}

/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[]) {
    int n;
    for (n = strlen(s) - 1; n >= 0; n--)
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    s[n + 1] = '\0';
    return 0;
}