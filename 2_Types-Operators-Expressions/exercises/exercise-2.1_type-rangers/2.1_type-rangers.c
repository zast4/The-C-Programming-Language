#include <stdio.h>
#include <limits.h>

int main() {
    printf("TYPE\t\t\tFROM\t\t\tTO\n");
    printf("char range:\t\t%d\t\t\t%d\n", CHAR_MIN, CHAR_MAX);
    printf("short range:\t\t%d\t\t\t%d\n", SHRT_MIN, SHRT_MAX);
    printf("integer range:\t\t%d\t\t%d\n", INT_MIN, INT_MAX);
    printf("long range:\t\t%ld\t%ld\n", LONG_MIN, LONG_MAX);
    printf("-----------------------------------------------\n");
    printf("unsigned char range:\t%d\t\t\t%d\n", 0, UCHAR_MAX);
    printf("unsigned short range:\t%d\t\t\t%d\n", 0, USHRT_MAX);
    printf("unsigned integer range:\t%d\t\t\t%u\n", 0, UINT_MAX);
    printf("unsigned long range:\t%d\t\t\t%lu\n", 0, ULONG_MAX);
    return 0;
}