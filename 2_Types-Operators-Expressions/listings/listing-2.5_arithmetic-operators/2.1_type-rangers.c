#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("----------------------------------------------------------------------------------------------\n");
    printf("TYPE \t\t\t   FROM \t\t\t TO \t\t\t SIZE IN BYTES\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("char range: \t\t   %d \t\t\t %d \t\t\t %lu\n", CHAR_MIN, CHAR_MAX, sizeof(char));
    printf("short range: \t\t   %d \t\t\t %d \t\t\t %lu\n", SHRT_MIN, SHRT_MAX, sizeof(short));
    printf("integer range: \t\t   %d \t\t\t %d \t\t %lu\n", INT_MIN, INT_MAX, sizeof(int));
    printf("long range: \t\t   %ld \t %ld \t %lu\n", LONG_MIN, LONG_MAX, sizeof(long));
    printf("long long range: \t   %lld \t %lld \t %lu\n", LLONG_MIN, LLONG_MAX, sizeof(long long));
    printf("----------------------------------------------------------------------------------------------\n");
    printf("unsigned char range: \t   %d \t\t\t\t %d \t\t\t %lu\n", 0, UCHAR_MAX, sizeof(unsigned char));
    printf("unsigned short range: \t   %d \t\t\t\t %d \t\t\t %lu\n", 0, USHRT_MAX, sizeof(unsigned short));
    printf("unsigned integer range:\t   %d \t\t\t\t %u \t\t %lu\n", 0, UINT_MAX, sizeof(unsigned int));
    printf("unsigned long range: \t   %d \t\t\t\t %lu \t %lu\n", 0, ULONG_MAX, sizeof(unsigned long));
    printf("unsigned long long range:  %d \t\t\t\t %llu \t %lu\n", 0, ULLONG_MAX, sizeof(unsigned long long));
    printf("----------------------------------------------------------------------------------------------\n");
    printf("float range: \t\t   %e \t\t %e \t\t %lu\n", FLT_MIN, FLT_MAX, sizeof(float));
    printf("double range: \t\t   %e \t\t %e\t\t %lu\n", DBL_MIN, DBL_MAX, sizeof(double));
    printf("----------------------------------------------------------------------------------------------\n");
    return 0;
}