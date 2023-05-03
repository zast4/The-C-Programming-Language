#include <stdio.h>
#include "ae.h"

#define MAXLINE 1000 /* максимальный размер вводимой строки */

int getLine(char linef[], int size);
void copy(char to[], char fromf[]);
void reverse(char usual[]);

int main() {
    a = 1;
//    int len; /* длина текущей строки */
//    int max; /* длина максимальной из просмотренных строк */
//    char line[MAXLINE]; /* текущая строка */
//    char longest[MAXLINE]; /* самая длинная строка */
//
//    max = 0;
//    while (getLine(line, MAXLINE)) {
//        reverse(line);
//        printf("%s", line);
//    }
    printf("%d", a);
    return 0;
}

int getLine(char linef[], int size) {
    int c, i;
    for (i = 0; i < size - 1 && (c = getchar()) != 'q' && c != '\n'; i++){
        linef[i] = c;
    }
    if (c == '\n') {
        linef[i] = c;
        i++;
    }
    linef[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

void reverse(char usual[]) {
    int size = 0;
    int temp;
    for (int i = 0; usual[i] != '\0'; ++i)
        ++size;
    size--;
    for (int i = 0; i != size / 2 - 1; ++i) {
        temp = usual[i];
        usual[i] = usual[size - i - 1];
        usual[size - i - 1] = temp;
    }
    usual[size + 1] = '\n';
}
