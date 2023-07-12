#include <stdio.h>

#define max(A, B) ((A) > (B) ? (A) : (B))

#define dprint(expr) printf(#expr " = %d\n", expr)
#define square(x) (x) * (x)
#define paste(front, back)  front ## back

int main() {
    // int z = 1;
    // dprint(square(z + 1));

    int paste(z, 2) = 2;
    printf("%d", z2);
    return 0;
}