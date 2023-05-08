#include <stdio.h>

/* копирование ввода на вывод; 1-я версия */
int main() {
    int last, current;
    while ((current = getchar()) != EOF) {
        if (last != ' ' || current != ' ')
            putchar(current);
        last = current;
    }
    return 0;
}