#include <ctype.h>
#include <stdio.h>

#define SIZE 100

#define dprint(expr) printf(#expr " = %d\n", expr)

int n, array[SIZE], getint(int *pn);

int main() {
    int res = -2;
    for (n = 0; n < SIZE && (res = getint(&array[n])) != EOF; ) {
        (res != 0) ? n++ : 0;
        printf("storing in n = %d, getint %d\n", n, array[n]);
    }

    printf("storing in n = %d, getint %d\n", n, array[n]);

    for (int i = 0; i < n; ++i) {
        printf("int%d: %d\n", i, array[i]);
    }
    return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn) {
    int c, sign;
    while (isspace(c = getchar()))  /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetc(c, stdin);  /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') 
        c = getchar();
    
    for (*pn = 0; isdigit(c); c = getchar())
        *pn = 10 * (*pn) + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetc(c, stdin);
    return c;
}