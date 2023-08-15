/* Implement a simple version of the #define processor (i.e, no arguments)
 * suitable for use with  C programs, based on the routines of this section.
 * You may also find getch and ungetch helpful.
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>

#define MAXWORD 1000
#define HASHSIZE 101
#define IN 1
#define OUT 0

int getword(char *, int, int *);

struct nlist {              /* table entry: */
    struct nlist *next;     /* next entry in chain */
    char *name;             /* defined name */
    char *defn;             /* replacement text */
};

static struct nlist *hashtab[HASHSIZE];     /* pointer table */

struct nlist *lookup(char *s);

/* hash: form hash value for string s */
unsigned hash(char *s) {
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s) {
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;              /* found */
    return NULL;                    /* not found */
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {  /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else      /* already there */
        free((void *) np->defn);        /* free previous defn */
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

struct nlist *undef(char *name) {
    struct nlist *found;
    found = lookup(name);

    if (found == NULL)  /* not found and nothing to do */
        return NULL;
    else {
        if (found->next != NULL) {
            found->next = found->next->next;
            found = found->next;
        } else {
            hashtab[hash(name)] = NULL;
            free((void *) found);
        }
    }
    return found;
}

int getword(char *word, int lim, int *lineno_addr) {
    int c, d, comment, string, directive;
    char *w = word;

    comment = string = directive = OUT;

    while (isspace(c = getchar())) {        /* skip spaces and new lines */
        if (c == '\n')
            *lineno_addr = *lineno_addr + 1;
    }

    /* Check if inside a comment */
    if (c == '/') {
        if ((d = getchar()) == '*') {
            comment = IN;
        } else {
            comment = OUT;
        }
    }

    /* Check if inside a quote */
    if (c == '\"') {
        string = IN;
    }

    /* Check if inside a directive */
    if (c == '#') {
        directive = IN;
    }

    if (c == '\\') {
        c = getchar(); /* ignore the \\ character */
    }

    if (comment == OUT && string == OUT && directive == OUT) {
        if (c != EOF)
            *w++ = c;
        
        if (!isalnum(c) && c != '_') {
            *w = '\0';
            return c;
        }

        for (; --lim > 0; w++) {
            *w = getchar();
            if (!isalnum(*w) && *w != '_') {
                ungetc(*w, stdin);
                break;
            }
        }
        *w = '\0';
        return word[0];
    } else if (comment == IN) {
        *w++ = c;
        *w++ = d;

        while ((*w++ = c = getchar())) {
            if (c == '*') {
                if ((c = getchar()) == '/') {
                    *w++ = c;
                    comment = OUT;
                    break;
                } else {
                    ungetc(c, stdin);
                }
            }
        }
        *w = '\0';
    } else if (string == IN) {
        *w++ = c;
        while ((*w++ = getchar()) != '\"') {
            if (*w == '\\')     /* Take care of escaped quotes */
                *w++ = getchar();
        }
        string = OUT;
        *w = '\0';
    } else if (directive == IN) {
        *w++ = c;
        while ((*w++ = getchar()) != ' ') {
            if (c == '\\') {    /* Take care of continuation line escape */
                *w++ = getchar();
            }
        }

        directive = OUT;
        *w = '\0';
    }
    return c;
}

int main(void) {
    int lineno = 0;
    char word[MAXWORD];

    char key[MAXWORD], value[MAXWORD];

    struct nlist *result;

    while (getword(word, MAXWORD, &lineno) != 'x') {
        if (strcmp(word, "#define ") == 0) {
            getword(key, MAXWORD, &lineno);
            getword(value, MAXWORD, &lineno);
            install(key, value);
            result = lookup(key);
            printf("%s->%s", result->name, result->defn);
        }
    }
    return 0;
}