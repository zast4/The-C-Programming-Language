/* minscanf: minimalistic scanf function */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void minscanf(char *, ...);

int main() {
    int i;
    minscanf("%d", &i);
    printf("minscanf input: %d\n", i);

    char *a;
    minscanf("%s", a);
    printf("minscanf input: %s\n", a);

    float f;
    minscanf("%f", &f);
    printf("minscanf input: %f\n", f);

    int o;
    minscanf("%o", &o);
    printf("minscanf input in octal %o, in decimal %d\n", o, o);

    int x;
    minscanf("%x", &x);
    printf("minscanf input in hex %x, in decimal %d\n", x, x);
    return 0;
}

void minscanf(char *fmt, ...) {
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int *ival;
    float *fval;

    va_start(ap, fmt);  /* make fmt point to first unnamed arg */
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int *);
                scanf("%d", ival);
                break;
            case 'f':
                fval = va_arg(ap, float *);
                scanf("%f", fval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                scanf("%s", sval);
                break;
            case 'o':
                ival = va_arg(ap, int *);
                scanf("%o", ival);
                break;
            case 'x':
                ival = va_arg(ap, int *);
                scanf("%x", ival);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}