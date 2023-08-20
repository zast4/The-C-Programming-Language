#include <stdio.h>
#include <stdlib.h>

int isupper(int);

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\n')
            continue;

        if (isupper(c) == 1)
            printf("true\n");
        else
            printf("false\n");
    }
    return EXIT_SUCCESS;
}

int isupper(int c) {
    return c >= 'A' && c <= 'Z' ? 1 : 0;
}