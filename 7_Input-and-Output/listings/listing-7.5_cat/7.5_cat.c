#include <stdio.h>

/* cat: concatenate files, version 1 */

int main(int argc, char *argv[]) {
    FILE *fp;
    void file_copy(FILE *, FILE *);

    if (argc == 1)  /* no args; copy standard input */
        file_copy(stdin, stdout);
    else
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL) {
                printf("cat: can't open %s\n", *argv);
                return 1;
            } else {
                file_copy(fp, stdout);
                fclose(fp);
            }
    return 0;
}

/* filecopy: copy the file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp) {
    int c;

    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}