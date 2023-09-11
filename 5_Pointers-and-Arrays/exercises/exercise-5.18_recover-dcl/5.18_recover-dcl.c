/* Make dcl recover from input errors */

#include "5.18_recover-dcl.h"

extern int prevtoken;

/* dcl: parse a declarator */
void dcl(void) {
    int ns;

    for (ns = 0; gettoken() == '*'; )   /* count *'s */
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
void dirdcl(void) {
    int type;

    if (tokentype == '(') {             /* ( dcl ) */
        dcl();
        if (tokentype != ')')
            errmsg("error: missing )\n");
    } else if (tokentype == NAME)       /* variable name */
        strcpy(name, token);
    else
        errmsg("error: expected name or (dcl)\n");
    while ((type = gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}

void errmsg(char *msg) {
    printf("%s", msg);
    prevtoken = YES;
}