#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 1000

#define dprint(expr) printf(#expr " = %d", expr)

/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[]) {
    size_t bufsize = MAXLINE;
    char* line = malloc(bufsize * sizeof(char));
    int found = 0;

    if (argc != 2)
        printf("Usage: find pattern\n");
    else
        while (getline(&line, &bufsize, stdin) > 0)
            if (strstr(line, argv[1]) != NULL) {
                printf("%s", line);
                found++;
            }
    return found;
}