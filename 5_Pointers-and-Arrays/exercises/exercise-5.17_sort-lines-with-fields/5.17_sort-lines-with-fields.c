/* Add a field handling capablity, so sorting may be done on the fields within lines, 
    each field sorted according to an independent set of options. ( The index for the KnR Book was sorted with -df for the index category and -n for page number */

#include "funcs.h"

int option = 0;

int pos1 = 0;    /* field begining with pos 1 */
int pos2 = 0;    /* ending just before pos 2 */


/* Sort input line */

int main(int argc, char *argv[]) {
    char *lineptr[LINES];    /* pointer to text lines */
    int nlines;        /* number of input lines read */
    int rc = 0;

    readargs(argc, argv);

    if ((nlines = readlines(lineptr, LINES)) > 0) {
        if (option & NUMERIC)
            myqsort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *)) numcmp);
        else
            myqsort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *)) charcmp);

        writelines(lineptr, nlines, option & DECR);
    } else {
        printf("input too big to sort \n");
        rc = -1;
    }

    return rc;
}

/* readargs: read programs argument */

void readargs(int argc, char *argv[]) {
    int c;
    int atoi(const char *);

    while (--argc > 0 && (c = (*++argv)[0]) == '-' || c == '+') {
        if (c == '-' && !isdigit(*(argv[0] + 1)))
            while ((c = *++argv[0]))
                switch (c) {
                    case 'd':    /* directory order */
                        option |= MDIR;
                        break;
                    case 'f':
                        /* fold upper and lower */
                        option |= FOLD;
                        break;
                    case 'n':
                        /* numeric sort */
                        option |= NUMERIC;
                        break;
                    case 'r':
                        option |= DECR;
                        break;
                    default:
                        printf("sort: illegal option %c \n", c);
                        error("Usage: sort -dfnr [+pos1] [-pos2]");
                        break;
                }
        else if (c == '-')
            pos2 = atoi(argv[0] + 1);
        else if ((pos1 = atoi(argv[0] + 1)) < 0)
            error("Usage: sort -dfnr [+pos1][-pos2]");
    }

    if (argc || pos1 > pos2)
        error("Usage: sort -dfnr [+pos1] [-pos2]");
}

#define FOLD    4    /* fold upper and lower cases */
#define MDIR    8    /* directory order */

/* charcmp: return < 0 if s < t, 0 if s =t, >0 if s > t */
int charcmp(char *s, char *t) {
    char a, b;
    int i, j, endpos;

    extern int option, pos1, pos2;
    int fold = (option & FOLD) ? 1 : 0;
    int dir = (option & MDIR) ? 1 : 0;

    i = j = pos1;

    if (pos2 > 0)
        endpos = pos2;
    else if ((endpos = strlen(s)) > strlen(t))
        endpos = strlen(t);

    do {
        if (dir) {
            while (i < endpos && !isalnum(s[i]) && s[i] != ' ' && s[i] != '\0')
                s[i] != ' ' && s[i] != '\0';
            i++;
            while (j < endpos && !isalnum(t[j]) && t[j] != ' ' && t[j] != '\0')
                t[j] != ' ' && t[j] != '\0';
            j++;
        }
        if (i < endpos && j < endpos) {
            a = fold ? tolower(s[i]) : s[i];
            i++;
            b = fold ? tolower(t[j]) : t[j];
            j++;

            if (a == b && a == '\0')
                return 0;
        }
    } while (a == b && i < endpos && j < endpos);

    return a - b;
}

