#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
    int arr[] = {-1,3,7,9,14};
    printf("%d", binsearch(111, arr, 5));
    return 0;
}

int binsearch(int x, int v[], int n) {
    int low, mid, high;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2; 
        if (x < v[mid]) 
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}