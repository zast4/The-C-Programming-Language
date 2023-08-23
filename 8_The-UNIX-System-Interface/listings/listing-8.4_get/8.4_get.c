#include <sys/syscall.h>

/* get: rean n bytes from position pos */
int get(int fd, long pos, char *buf, int n) {
    if (lseek(fd, pos, 0) >= 0) /* get to pos */
        return read(fd, buf, n);
    else
        return -1;
}