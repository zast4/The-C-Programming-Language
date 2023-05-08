#include <stdio.h>

/* Write a program to count blanks, tabs, and newlines. */

int main() {
    int c, spaces = 0, tabs = 0, nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') ++spaces;
        if (c == '\t') ++tabs;
        if (c == '\n') ++nl;
    }
    printf("spaces: %d\n", spaces);
    printf("tabs: %d\n", tabs);
    printf("new lines: %d\n", nl);
    return 0;
}