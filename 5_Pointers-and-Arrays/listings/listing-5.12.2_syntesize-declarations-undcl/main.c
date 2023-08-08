#include "5.12.2_syntesize-declarations-undcl.h"

int main() {    /* convert declaration to words */
    int type;
    char temp[MAXTOKEN];

    while (gettoken() != EOF) {         /* 1st token on line */
        strcpy(out, token);
        // printf("token: %s\n", token);
        while ((type = gettoken()) != '\n')
            if (type == PARENS || type == BRACKETS)
                strcat(out, token);
            else if (type == '*') {
                if ((type = nexttoken()) == PARENS || type == BRACKETS)
                    sprintf(temp, "(*%s)", out);
                else
                    sprintf(temp, "*%s", out);  // remove redundant braces
                strcpy(out, temp);
            } else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } else
                printf("invalid input at %s\n", token);
        printf("%s\n", temp);  
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

/* nexttoken: get the next token and push it back */
int nexttoken(void) {
    int type;
    extern int prevtoken;

    type = gettoken();
    prevtoken = YES;
    return type;
}