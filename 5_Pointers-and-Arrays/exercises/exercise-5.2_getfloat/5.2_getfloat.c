#include <ctype.h>
#include <stdio.h>

#define SIZE 100

#define dprint(expr) printf(#expr " = %d\n", expr)

float array[SIZE];
int n, getfloat(float *pn);

int main() {
    int res = -2;
    for (n = 0; n < SIZE && (res = getfloat(&array[n])) != EOF; ) {
        (res != 0) ? n++ : 0;
        printf("storing in n = %d, getfloat %f\n", n, array[n]);
    }

    printf("storing in n = %d, getfloat %f\n", n, array[n]);

    for (int i = 0; i < n; ++i) {
        printf("int%d: %f\n", i, array[i]);
    }
    return 0;
}

/* getfloat: get next float from input into *pn */
int getfloat(float *pn) {
    int c, sign;
    float power;
    while (isspace(c = getchar()))  /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetc(c, stdin);  /* it is not a number */
        return -1;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') 
        c = getchar();

    /* If we read '+' or '-' and then there is no numbers, we don't treat it like a representation of zero */
    if (!isdigit(c) && c != EOF)
        return 0;
    
    for (*pn = 0; isdigit(c); c = getchar())
        *pn = 10 * (*pn) + (c - '0');
    if (c == '.')
        c = getchar();

    for (power = 1.0; isdigit(c); c = getchar()) {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;
    }
    *pn *= sign / power;
    if (c != EOF)
        ungetc(c, stdin);
    return c;
}