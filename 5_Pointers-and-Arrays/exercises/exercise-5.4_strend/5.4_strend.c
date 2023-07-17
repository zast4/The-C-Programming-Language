#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);

int main() {
    char s1[] = "abc";
}

int strend(char *s, char *t) {
    int len_t = strlen(t);
    while (*s++ != '\0');
    while (*t++ != '\0');
    --s;
    --t;
    while (len_t > 0) {
        if (*t-- == *s--)
            len_t--;
        else
            return 0;
    }
    if (len_t == 0)
        return 1;
}