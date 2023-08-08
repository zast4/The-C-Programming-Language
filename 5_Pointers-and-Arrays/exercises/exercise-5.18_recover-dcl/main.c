#include "5.18_recover-dcl.h"

int main() {    /* convert declaration to words */
    while (gettoken() != EOF) {         /* 1st token on line */
        strcpy(datatype, token);        /* is the datatype */
        out[0] = '\0';
        dcl();              /* parse rest of line */
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

int prevtoken = NO;

int gettoken(void) {  /* return next token */
    int c;
    char *p = token;

    if (prevtoken == YES) {
        prevtoken = NO;
        return tokentype;
    }

    while ((c = getchar()) == ' ' || c == '\t')
        ;
    if (c == '(') {
        if ((c = getchar()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetc(c, stdin);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getchar()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getchar()); )
            *p++ = c;
        *p = '\0';
        ungetc(c, stdin);
        return tokentype = NAME;
    } else
        return tokentype = c;
}