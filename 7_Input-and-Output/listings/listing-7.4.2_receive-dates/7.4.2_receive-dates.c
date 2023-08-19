#include <stdio.h>
#include <stdlib.h>

int main() {
    int day, year;
    int month;
    size_t size = 100;
    char *line = malloc(size * sizeof(char));

    char monthname[20];

    // scanf("%d %s %d", &day, monthname, &year);
    // or
    // scanf("%d/%d/%d", &month, &day, &year);
    // printf("%d/%.2d/%d", month, day, year);

    while (getline(&line, &size, stdin) > 0) {
        if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
            printf("valid: %s\n", line);    /* 25 Dec 1988 form */
        else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
            printf("valid: %s\n", line);    /* mm/dd/yy form */
        else {
            printf("invalid: %s\n", line);  /* invalid form */
        }
    }
    free(line);
    return 0;
}