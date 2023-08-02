#include <stdio.h>
#include <stdlib.h>

#define dprint(expr) printf(#expr " = %d\n", expr)

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (year < 1 || month < 1 || month > 12 || day < 1 || day > *(*(daytab + leap) + month))
        return -1;

    for (i = 1; i < month; i++)
        day += *(*(daytab + leap) + i);
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (year < 1 || yearday < 1 || yearday > (leap ? 366 : 365)) {
        *pmonth = -1;
        *pday = -1;
        return;
    }

    for (i = 1; yearday > *(*(daytab + leap) + i); i++)
        yearday -= *(*(daytab + leap) + i);
    *pmonth = i;
    *pday = yearday;
}

int main() {
    dprint(*(*(daytab + 1) + 1));
    dprint(day_of_year(2023, 7, 31));
    int *month = malloc(4);
    int *day = malloc(4);
    month_day(2023, 212, month, day);
    dprint(*month);
    dprint(*day);
}