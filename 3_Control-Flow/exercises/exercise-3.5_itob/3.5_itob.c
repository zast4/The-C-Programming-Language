/* function itob(n,s,b), that converts the integer n into a base b character
 * representation in the string s.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {
    char s[MAXLINE];
    printf("%s", s);
    return 0;
}

void itob(int n, char s[], int b) {
    int i, rem, sign;
    i = 0;
    sign = n;
    n = n < 0 ? -n : n;
    do {
        rem = n % b;
        s[i++] = (rem <= 9) ? rem + '0' : rem + 'a' - 10;
    } while ((n /= b) != 0);
    if (sign < 0) 
        s[i] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int i, j, c;
    for (i = 0, j = strlen(s) - 1; i < j; ++i, --j)
        c = s[i], s[i] = s[j], s[j] = c;
}