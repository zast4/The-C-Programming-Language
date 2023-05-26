#include <stdio.h>

/*  Write a program to print a histogram of the lengths of words
 * in its input. */

int main() {
    int c;  // Current symbol
    int word_lengths[100];  // Array to keep length of words
    int count_words;
    int wordlen = 0;  // Length of the current word
    for (count_words = 0; count_words < 100; ++count_words)
        word_lengths[count_words] = 0;
    count_words = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n') {
            ++count_words;
            wordlen = 0;
        }
        else {
            word_lengths[count_words] = ++wordlen;
        }
    }
    for (int j = 0; j <= count_words; ++j) {
        printf("\n%d: ", j + 1);
        for (int wordlen = 0; wordlen < word_lengths[j]; ++wordlen)
            printf("-");
    }
    return 0;
}