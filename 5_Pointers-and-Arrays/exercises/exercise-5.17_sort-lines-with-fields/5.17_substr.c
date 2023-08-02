/* The source file substr.c */

#include "funcs.h"

void error(char *);

/* substr: get a substring of S and put in str */

void substr(char *s, char *t, int maxstr) {
    int i, j, len;
    extern int pos1, pos2;

    len = strlen(s);

    if (pos2 > 0 && len > pos2)
        len = pos2;
    else if (pos2 > 0 && len < pos2)
        error("substr: string too short");
    for (j = 0, i = pos1; i < len; i++, j++)
        t[j] = t[i];
    t[j] = '\0';
}

/* error: print error message and exit */

void error(char *s) {
    printf("%s \n", s);
    exit(1);
}


void swap(void *v[], int i, int j) {
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* myqsort: sort v[left] ... v[right] into increasing order */

void myqsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)        /* do nothing if array contains */
        return;

    swap(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);

    myqsort(v, left, last - 1, comp);
    myqsort(v, last + 1, right, comp);
}


#define MAXLEN    1000        /* max length of any input line  */

int mgetline(char *, int);

char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = mgetline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';    /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines, int decr) {
    if (decr)  /* print in decreasing order */
        for (int i = nlines - 1; i >= 0; i--)
            printf("%s\n", lineptr[i]);
    else
        for (int i = 0; i < nlines; i++)
            printf("%s\n", lineptr[i]);
}

#define ALLOCSIZE 10000            /* size of available space */

static char allocbuf[ALLOCSIZE];    /* storage for alloc */
static char *allocp = allocbuf;        /* next free position */

char *alloc(int n)            /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;    /* old p */
    } else                /* not enough room */
        return 0;
}

void afree(char *p)        /* free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}


/* mgetline: read a line into s,return length */

int mgetline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}