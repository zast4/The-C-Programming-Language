#include <unistd.h>

#define EOF -1

/* getchar: unbuffered single character input */
int getchar(void) {
    char c;

    return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

int main() {
    getchar();
    return 0;
}