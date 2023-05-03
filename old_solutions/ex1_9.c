#include <stdio.h>
/* подсчет строк входного потока */
int ex_1_9()
{
    int c, countSpaces = 0;
    while ((c = getchar()) != 'q') {
        if (c == ' ' && countSpaces == 0)
            putchar(c);
        if (c == ' ')
            ++countSpaces;
        else {
            countSpaces = 0;
            putchar(c);
        }
    }
    return 0;
}