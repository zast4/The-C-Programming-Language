#include <stdio.h>

/* подсчет вводимых символов */
int main() {
    long nc = 0;
    while (getchar() != 'q')
        ++nc;
    printf("%ld\n", nc);
}