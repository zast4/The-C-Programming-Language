#include <stdio.h>
#include <stdlib.h>

void strcat(char *s, char *t) {
    while (*s++);
    s--;
    while (*s++ = *t++);
}

int main() {
    char *s1 = malloc(sizeof(char) * 1);
    s1[0] = 'a', s1[1] = 'b', s1[2] = 'c';
    char *s2 = "def";

    strcat(s1, s2);
    printf("%s\n", s1);
    for (int i = 0; i < 8; ++i) {
        printf("%c", s1[i]);
    }
    return 0;
}