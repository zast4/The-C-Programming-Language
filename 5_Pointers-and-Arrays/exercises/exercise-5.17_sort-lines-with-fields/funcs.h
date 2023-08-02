#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define NUMERIC  1    /* numeric sort */
#define DECR    2    /* sort in decreasing order */
#define FOLD    4    /* fold upper and lower case */
#define MDIR    8    /* directory order */
#define LINES    100    /* maximum number of lines to be sorted */

int charcmp(char *, char *);

void error(char *);

int numcmp(char *, char *);

void readargs(int argc, char *argv[]);

int readlines(char *lineptr[], int maxlines);

void mqsort(void *v[], int left, int right, int (*comp)(void *, void *));

void writelines(char *lineptr[], int nlines, int order);

void substr(char *s, char *t, int maxstr);

void myqsort(void *v[], int left, int right, int (*comp)(void *, void *));