#include <stdio.h>

/* Experiment to find out what happens when prints's argument string contains
\c, where c is some character not listed above. */

int main() {
    // This code will just print "c" because it's not an escape sequence
    printf("Hello world!\c");
    return 0;
}