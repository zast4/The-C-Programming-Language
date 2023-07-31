#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000  /* max #lines to be sorted */
#define MAXLEN 1000

char *lineptr[MAXLINES];  /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void _qsort(char *v[], int left, int right);
void swap(char *v[], int i, int j);

/* sort input lines */
int main() {
    int nlines;  // number of input lines read

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        _qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
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
void writelines(char *lineptr[], int nlines) {
    for (int i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* qsort: sort v[left]...v[right] into increasing order */
void _qsort(char *v[], int left, int right) {
    int i, last;
    if (left >= right)  // do nothing if an array contains 
        return;         // fewer than 2 elements
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    _qsort(v, left, last - 1);
    _qsort(v, last + 1, right);
}