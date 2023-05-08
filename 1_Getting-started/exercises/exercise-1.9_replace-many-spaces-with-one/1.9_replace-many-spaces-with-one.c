#include <stdio.h>

/* Write a program to copy its input to its output,
 * replacing each string of one or
 * more blanks by a single blank. */

int main() {
    int last, current;
    while ((current = getchar()) != EOF) {
        if (last != ' ' || current != ' ')
            putchar(current);
        last = current;
    }
    return 0;
}