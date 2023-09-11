/* a function of itoa, which accepts the third argument as the width of the
number. the string representation is padded with blanks in the left to get the
required width */

#include <stdio.h> 
#include <ctype.h>
#include <string.h>

void itoa(int n, char s[], int width);
void reverse (char s[]);

int main() {
    int n = 0;
    char s[1000];
    int width = 4;
    itoa(n, s, width);
    printf("%s", s);
    return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[], int width) {
    int i, sign;
    if ((sign = n) < 0) 
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    while (width - i > 0)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}