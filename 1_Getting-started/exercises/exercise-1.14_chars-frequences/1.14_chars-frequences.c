#include <stdio.h>
#include <limits.h>

/*  Write a program to print a histogram of the frequencies of different characters in its input */

int main() {
    int c;  // Current symbol
    int i;
    int chars[CHAR_MAX];
    for (i = 0; i < CHAR_MAX; ++i)
        chars[i] = 0;
    for (i = 0; (c = getchar()) != 'q'; ++i)
        ++chars[c];
    for (i = 0; i < CHAR_MAX; ++i)
        if (chars[i] != 0) {
            printf("%c: ", i);
            for (int j = 0; j < chars[i]; ++j)
                putchar('-');
            putchar('\n');
        }
    return 0;
}