#include <unistd.h>

#define BUFSIZ 100
#define EOF -1

/* getchar: simple buffered version */
int getchar(void) {
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;

    if (n == 0) {   /* buffer is empty */
        n = read(0, buf, sizeof buf);
        bufp = buf;
    }
    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

int main() {
    getchar();
    getchar();
    getchar();
    return 0;
}