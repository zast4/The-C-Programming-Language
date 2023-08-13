#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS (sizeof(keytab) / sizeof(keytab[0]))

struct key {
    char *word;
    int count;
} keytab[] = {"auto", 0, "break", 0, "case", 0, "char", 0,
              "const", 0, "continue", 0, "default", 0, "do", 0,
              "double", 0, "else", 0, "enum", 0, "extern", 0,
              "float", 0, "for", 0, "goto", 0, "if", 0,
              "int", 0, "long", 0, "register", 0, "return", 0,
              "short", 0, "signed", 0, "sizeof", 0, "static", 0,
              "struct", 0, "switch", 0, "typedef", 0, "union", 0,
              "unsigned", 0, "void", 0, "volatite", 0, "while", 0};

int getword(char *, int);
struct key *binsearch(char *word, struct key tab[], int n);

/* count C keywords; pointer version */
int main() {
    char word[MAXWORD];
    struct key *p;

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((p = binsearch(word, keytab, NKEYS)) != NULL)
                p->count++;
    for (p = keytab; p < keytab + NKEYS; p++)
        if (p->count > 0)
            printf("%4d %s\n", p->count, p->word);
    return 0;
}

/* binsearch: find word in tab[0] ... tab[n - 1] */
struct key *binsearch(char *word, struct key tab[], int n) {
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n - 1];
    struct key *mid;

    while (low < high) {
        mid = low + (high - low) / 2
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return NULL;
}

/* getword: get next word or character from input */
int getword(char *word, int lim) {
    int c;
    char *w = word;
    int t;

    while (isspace(c = getchar()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        if (c == '\"') { /* string constant */
            for (c = getchar(); c != '\"'; c = getchar())
                ;
        } else if (c == '#') { /* preprocessor */ 
            for (c = getchar(); c != '\n'; c = getchar())
                ;
        } else if (c == '/') { /* comment */
            if ((c = getchar()) == '/') { /* single comment */
                for (c = getchar(); c != '\n'; c = getchar())
                    ;
            }
            else if (c == '*') { /* multiline comment */
                for (c = getchar(), t = getchar(); c != '*' && t != '/'; c = getchar(), t = getchar())
                    ungetc(t, stdin);
            } else {
                ungetc(c, stdin);
            }
        } else { /* underscore */
            for (; !isspace(c) && c != EOF; c = getchar());
        }
        if (c != '\"' && c != '\n' && c != '/')
            ungetc(c, stdin);
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getchar())) {
            ungetc(*w, stdin);
            break;
        }
    *w = '\0';
    return word[0];
}