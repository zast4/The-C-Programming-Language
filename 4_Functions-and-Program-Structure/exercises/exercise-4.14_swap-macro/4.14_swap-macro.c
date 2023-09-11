/* a macro swap(t,x,y) that interchanges two arguments of type t */

#include <stdio.h>
#include <math.h>

#define swap(t, x, y) { t z = x; \
                        x = y; \
                        y = z; \
                      }

int main() {
    int x = 1;
    int y = 2;
    printf("%d %d\n", x, y);
    swap(int, x, y);
    printf("%d %d", x, y);
    return 0;
}