#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *f_gets(char *line, int maxline, FILE *fp);
int f_puts(char *line, FILE *fp);
int get_line(char *line, int max);

int main() {
    char *line = malloc(sizeof(char) * 100);
    line = f_gets(line, 100, stdin);
    printf("line 1: %s", line);
    f_puts(line, stdout);

    char *line2 = malloc(sizeof(char) * 100);
    get_line(line2, 100);
    printf("line 2: %s", line2);

    free(line);
    free(line2);
    return 0;
}

/* fgets: get at most n chars from iop */
char *f_gets(char *s, int n, FILE *iop) {
    register int c;
    register char *cs;

    cs = s;
    while (--n > 0 && (c = getc(iop)) != EOF)
        if ((*cs++ = c) == '\n')
            break;
    *cs = '\0';
    return (c == EOF && cs == s) ? NULL : s;
}

/* fputs: put string s on file iop */
int f_puts(char *s, FILE *iop) {
    int c;

    while ((c = *s++))
        putc(c, iop);
    return ferror(iop) ? EOF : 0;
}

/* getline: read a line, return length */
int get_line(char *line, int max) {
    if (fgets(line, max, stdin) == NULL)
        return 0;
    else
        return strlen(line);
}