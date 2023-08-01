#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define dprint(expr) printf(#expr " = %s\n", expr)

#define MAXOP 100
#define NUMBER '0'
#define BUFSIZE 100
#define MAXVAL 100  // maximum depth of value of stack

int sp = 0;  // next free position in stack
double val[MAXVAL];  // stack

int getop(char[]);
void push(double);
double pop(void);
void ungets(char[]);

int main(int argc, char *argv[]) {
    char s[MAXOP];
    double op2;
    while (--argc > 0) {
        ungets(" ");
        ungets(*++argv);  // just unget every argument to stdin, and use the same functions as before. Profit

        switch (getop(s)) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor \n");
                break;
            default:
                printf("error: unknown command %s \n", s);
                argc = 1;
                break;
        }
    }
    printf("\t %8g\n", pop());

    return 0;
    
}

/* getop: get next operator or numeric operand */

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getchar()) == ' ' || c == '\t');

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;

    i = 0;

    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getchar()));
    if (c == '.') /* collect from fraction part */
        while (isdigit(s[++i] = c = getchar()));
    s[i] = '\0';

    if (c != EOF)
        ungetc(c, stdin);
    return NUMBER;
}

/* push : push f onto value stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g \n", f);
}

/* pop: pop and return top value from the stack */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty \n");
        return 0.0;
    }
}

/* ungets: push string back onto the input */
void ungets(char s[]) {
    int len = strlen(s);

    while (len > 0)
        ungetc(s[--len], stdin);
}