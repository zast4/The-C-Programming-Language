/* Write a pointer version of the function strcat that we showed in Chapter 2: 
 * strcat(s,t) copies the string t to the end of s.
 */

#include <stdio.h>
#include <stdlib.h>

void strcat(char *s, char *t) {
    while (*s++);
    s--;
    while (*s++ = *t++);
}

int main() {
    char *s1 = malloc(sizeof(char) * 10);
    for (int i = 0; i < 3; ++i) {
        s1[i] = 'a';
    }
    s1[3] = '\0';
    //char s1[] = "abc";
    char s2[] = "def";

    strcat(s1, s2);
    for (int i = 0; i < 10; ++i) {
        printf("%c", *s1++);
    }
    return 0;
}