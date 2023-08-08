#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };
enum { NO, YES };

void dcl(void);
void dirdcl(void);

int gettoken(void);
int nexttoken(void);
int tokentype;                  /* type of last token */
char token[MAXTOKEN];           /* last token string */
char name[MAXTOKEN];            /* identifier name */
char datatype[MAXTOKEN];        /* data type = char, int, etc. */
char out[1000];