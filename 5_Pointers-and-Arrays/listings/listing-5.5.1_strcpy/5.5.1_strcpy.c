#include <stdio.h>
#include <stdlib.h>

/* strcpy: copy t to s; array subscript version */
void strcpy_a(char *s, char *t) {
    int i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

void strcpy_p1(char *s, char *t) {
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

void strcpy_p2(char *s, char *t) {
    while (*s++ = *t++);
}

int main() {
    char *s1 = malloc(sizeof(char) * 3);
    *s1 = 'a';
    *(s1 + 1) = 'b';
    *(s1 + 2) = 'c';
    char *s2 = malloc(sizeof(char) * 3);
    s2 = "deb";
    strcpy_p2(s1, s2);
    printf("%s", s1);
}