#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define dprint(expr) printf(#expr " = %d", expr);

#define LINES 5000  /* max #lines to be sorted */
#define MAXLEN 1000
#define NUMERIC 1
#define DECR 2
#define FOLD 4


int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int decr);

void q_sort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
void swap(void *v[], int, int);
int numcmp(char *, char *);
int str_cmp(char *s, char *t);
int str_cmp_f(char *s, char *t);

static char option = 0;

/* sort input lines */
int main(int argc, char *argv[]) {
    char *lineptr[LINES];  /* pointers to text lines */
    int nlines;  /* pointer to text lines */
    int c, rc = 0;  /* number of input lines read */
    //dprint('b');

    while (--argc > 0 && (*++argv)[0] == '-')
        while ((c = *++argv[0]))  // increment inside "-nr" string
            switch (c) {
                case 'n':  /* numeric sort */
                    option |= NUMERIC;
                    break;
                case 'r':  /* sort in decreasing order */
                    option |= DECR;
                    break;
                case 'f':  /* ignore case */
                    option |= FOLD;
                    break;
                default:
                    printf("sort:illegal option %c\n", c);
                    argc = 1;
                    rc = -1;
                    break;
            }
    if (argc)
        printf("Usage: sort -nr \n");
    else if ((nlines = readlines(lineptr, LINES)) > 0) {
        if (option & NUMERIC) 
            q_sort((void **) lineptr, 0, nlines - 1, (int (*) (void *, void *)) numcmp);
        else if (option & FOLD) {
            // dprint(4);
            q_sort((void **) lineptr, 0, nlines - 1, (int (*) (void *, void *)) str_cmp_f);
        }
        else
            q_sort((void **) lineptr, 0, nlines - 1, (int (*) (void *, void *)) str_cmp);

        writelines(lineptr, nlines, option & DECR);
    } else {
        printf("input too big to sort \n");
        rc = -1;
    }
    return rc;
}

/* q_sort: sort v[left]...v[right] into increasing order */
void q_sort(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    q_sort(v, left, last - 1, comp);
    q_sort(v, last + 1, right, comp);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v2 > v1)
        return 1;
    else
        return 0;
}

/* str_cmp: return <0 if s < t, 0 if s == t, >0 if s > t */
int str_cmp(char *s, char *t) {
    for ( ; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

void swap(void *v[], int i, int j) {
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p;
    char *line = malloc(MAXLEN * sizeof(char));
    size_t bufsize = MAXLEN;

    nlines = 0;
    while ((len = getline(&line, &bufsize, stdin)) > 0)
        if (nlines >= maxlines || ((p = (char *) malloc(len * sizeof(char))) == NULL))
            return -1;
        else {
            line[len - 1] = '\0';  // delete '\n'
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