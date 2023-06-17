#include <stdio.h>

int main() {
  int a[25] = {10,2,3,4,3,5,3,1,5,2,6,8,2,7,3,7,4,7,1,7,4,3,7,4,1};
  for (int i = 0; i < 25; ++i)
    printf("%6d%c", a[i], (i % 10 == 9) ? '\n' : ' ');
  return 0;
}