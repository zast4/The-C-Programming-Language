#include <stdio.h>
#include <limits.h>

int main() {

    printf("%d, %d\n", CHAR_MIN, CHAR_MAX);
    printf("%d, %d\n", SHRT_MIN, SHRT_MAX);
    printf("%d, %d\n", INT_MIN, INT_MAX);
    printf("%ld, %ld", LONG_MIN, LONG_MAX);
    return 0;
}