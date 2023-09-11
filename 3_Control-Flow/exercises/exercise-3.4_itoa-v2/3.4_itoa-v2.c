/* Modified version of itoa; to handle the situation of MIN_INT of limits.h
 * in the previous number = -2147483648 would fail at n =-n,because the max value
 * of integer is 2147483647
 * 
 * modifying itoa to handle these situations.
 * sign is stored as  the number itself, absolute value of each digit is stored in
 * the string and while loop is tested not for 0

 * itoa: convert an integer to string */

#include <stdio.h> 
#include <string.h>

#define abs(x) ((x) > 0 ? (x) : -(x))

void itoa(int n, char s[]);
void reverse (char s[]);

int main() {
    int n = -2147483648;
    char s[1000];
    itoa(n, s);
    printf("%s", s);
    return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]) {
    int i, sign;
    sign = n;
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
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