/**
 *
 * Program demonstrating atof(char s[]).The function which converts the string
 * to a floating point value.
 *
 */

#include <ctype.h>
#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
double atof(char s[]);
int power(int base, int exp);

int main() {
    char str[MAXLINE];
    double num;
    get_line(str, MAXLINE);
    num = atof(str);
    printf("%.10f", num);
    return 0;
}

double atof(char s[]) {
    int i, sign, esign, exp;
    double val, pow = 1.0;
    for (i = 0; isspace(s[i]); ++i)
        ;
    sign = (sign == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    for (val = 0.0; isdigit(s[i]); ++i)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        ++i;
    for (pow = 1.0; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
        pow *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E') 
        ++i;
    if (s[i] == '-' || s[i] == '+') {
        esign = s[i];
        ++i;
    }
    for (exp = 0; isdigit(s[i]); ++i)
        exp = 10.0 * exp + (s[i] - '0');
    
    if (esign == '-')
        return sign * (val / pow) / power(10, exp);
    else
        return sign * (val / pow) * power(10, exp);
}

int get_line(char s[], int lim) {
    int i, c;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\0')
        s[i++] = c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return i;
}

int power(int base, int exp) {
    int power = 1;
    while (exp-- > 0)
        power *= base;
    return power;
}