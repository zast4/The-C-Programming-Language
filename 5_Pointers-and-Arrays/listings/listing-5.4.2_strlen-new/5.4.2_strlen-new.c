#include <stdio.h>

/* strlen: return length of string s */
int strlen(char *s) {
    char *p = s;
    while (*p != '\0')
        p++;
    return p - s;
}

int main() {
    char *pmessage = "asdfasd";
    char *d = "d";
    *pmessage = *d;
    //printf("%s", pmessage);
    return 0;
}