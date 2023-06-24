#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
    int x[] = {1,2,5,9,14};
    printf("%d", binsearch(9, x, 5));
    return 0;
}

int binsearch(int x , int v[], int n) {
    int low, mid, high;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && v[mid] != x) {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (high + low) / 2;
    }
    if (x == v[mid])
        return mid;
    return -1;
}