#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 1000

#define dprint(expr) printf(#expr " = %d", expr)

/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[]) {
    size_t bufsize = MAXLINE;
    char* line = malloc(bufsize * sizeof(char));
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
        while ((c = *++argv[0]))
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
                }
    if (argc != 1)
        printf("Usage: find -x -n pattern\n");
    else
        while (getline(&line, &bufsize, stdin) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }
    return found;
}