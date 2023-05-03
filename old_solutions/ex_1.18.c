#include <stdio.h>
#define MAXLINE 1000 /* максимальный размер вводимой строки */


int getLine(char linef[], int size);
void copy(char to[], char fromf[]);

int main() {
    int len; /* длина текущей строки */
    int max; /* длина максимальной из просмотренных строк */
    char line[MAXLINE]; /* текущая строка */
    char longest[MAXLINE]; /* самая длинная строка */

    max = 0;
    while (getLine(line, MAXLINE)) {
        printf("%s", line);
    }
    //printf("%s", longest);
    return 0;
}

int getLine(char linef[], int size) {
    int c, i;
    int spacesTabs = 0;
    int letter = 0;
    for (i = 0; i < size - 1 && (c = getchar()) != 'q' && c != '\n'; i++){
        if (spacesTabs == 0 && (c == ' ' || c == '\t')) {
            spacesTabs++;
            linef[letter] = ' ';
            letter++;
        } else if (c != ' ' && c != '\t') {
            spacesTabs = 0;
            linef[letter] = c;
            letter++;
        }
    }
    if (c == '\n' && letter != 0) {
        linef[letter] = c;
        letter++;
    } else if (c == '\n') {
        return 1;
    }
    linef[letter] = '\0';
    return letter;
}

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
