/* Write a Program tail, which prints the last n lines of its input. 
 * By default n is 10. let us say; but it can be changed
 * by an optional argument so that tail -n
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFLINES 10  // default # of lines to print
#define LINES 100
#define MAXLEN 100

void error(char *);

int main(int argc, char *argv[]) {
    char *p;
    char *buf;  // pointer to the large buffer
    char *bufend;  // end of the large buffer
    size_t bufsize = MAXLEN;

    char* line = malloc(MAXLEN * sizeof(char));
    char *lineptr[LINES];  // pointer to lines read

    int first, i, last, len, n, nlines;

    if (argc == 1)
        n = DEFLINES;
    else if (argc == 2 && (*++argv)[0] == '-')
        n = atoi(argv[0] + 1);
    else
        error("Usage: tail [-n]");

    if (n < 1 || n > LINES)
        n = LINES;
    
    for (i = 0; i < LINES; i++)
        lineptr[i] = NULL;

    if ((p = buf = malloc(LINES * bufsize)) == NULL)
        error("tail: cannot allocate buf");
    bufend = buf + LINES + MAXLEN;

    last = 0;
    nlines = 0;

    while ((len = getline(&line, &bufsize, stdin)) > 0) {
        if (p + len + 1 >= bufend)
            p = buf;
        lineptr[last] = p;

        strcpy(lineptr[last], line);
        if (++last >= LINES)
            last = 0;

        p += len + 1;
        nlines++;
    }

    if (n > nlines)
        n = nlines;

    first = last - n;

    if (first < 0)
        first += LINES;

    for (i = first; n-- > 0; i = (i + 1) % LINES)
        printf("%s", lineptr[i]);

    return 0;
}

void error(char *s) {
    printf("%s\n", s);
    exit(1);
}