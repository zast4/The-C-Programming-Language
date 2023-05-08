#include <stdio.h>

/* копирование ввода на вывод */
int main() {
    int c;
    while ((c = getchar) != EOF)
        putchar(c);
}