/* Exercise 1-21. Write a program `entab` that replaces strings of
 * blanks by the minimum number of tabs and blanks to achieve the same
 * spacing. Use the same tab stops as for `detab`. When either a tab or
 * a single blank would suffice to reach a tab stop, which should be
 * given preference?
 */

#include <stdio.h>

#define TABSIZE 4

int main() {
    int spaces_count = 0;
    int tabs_count = 0;
    char c;

    for (int cur_pos = 1; (c = getchar()) != EOF; ++cur_pos) {
        if (c == ' ') {  // Count number of consecutive spaces
            if ((cur_pos % TABSIZE) != 0) {  // If current position ISN'T divisible by TABSIZE (8), we CAN'T replace this space(s) with tab and just increase num of consecutive spaces
                ++spaces_count;
            } 
            else {  // Now current position IS divisible by TABSIZE (8), so we CAN replace all previous consecutive spaces with ONE tab, and reset num of consecutive spaces
                ++tabs_count;
                spaces_count = 0;
            }
        } else {  // Here is we see that current symbol isn't a space
            for (; tabs_count > 0; --tabs_count)  // So we print all possible tabs instead of all consecutive spaces we went through
                putchar('\t');
            if (c == '\t')  // If cur symbol is tab, then all previous read spaces are useless and can't be replaces with this tab, so blank space will be the same
                spaces_count = 0;
            else
                for (; spaces_count > 0; --spaces_count)  // After we printed all possible tabs, print all possible spaces
                    putchar(' ');

            putchar(c);  // All other symbols (not tabs and spaces) will be printed just the way they are

            if (c == '\n')  // New line is encountered, it means that all blanks on this line has already been printed, so we can reset position and start processing new line
                cur_pos = 0;
            else if (c == '\t')  // If cur symb is tab, it means that our position whenever now it would be now has to be in the tabstop. Examples: cur_pos = 4 -> cur_pos = 8, cur_pos = 3 -> cur_pos = 8, cur_pos = 13 -> cur_pos = 16
                cur_pos = (cur_pos + TABSIZE) - (cur_pos + TABSIZE) % TABSIZE;  // Cur position after we met tab is calculated in the following way: we jump TABSIZE characters forward, then substract extra characters by getting the remainder after dividing by TABSIZE from this overestimation
        }
    }
    return 0;
}
