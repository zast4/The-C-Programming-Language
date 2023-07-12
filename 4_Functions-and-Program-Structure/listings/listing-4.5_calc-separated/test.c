#include <stdio.h>
#include <string.h>

int main() {
    char s1[] = "ould";
    char s2[] = {'o', 'u', 'l', 'd', '\0'};
    printf("s1 len: %lu", strlen(s1));
    printf("s2 len: %lu", strlen(s2));
}