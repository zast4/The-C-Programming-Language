/***
 *
 * Exercise 1-3. Modify the temperature conversion program,
 * Fahrenheit to Celsius, to print a heading above the table.
 *
 * print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300;
 * floating-point version.
 *
 ***/

#include <stdio.h>

/* Modify the temperature conversion program
 * to print a heading above the table. */

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;  // нижняя граница таблицы температур
    upper = 100;  // верхняя граница
    step = 10;  // шаг

    fahr = lower;
    printf("Celsius\tFahrenheit\n");
    while (celsius <= upper) {
        fahr = (9.0 / 5.0) * celsius + 32;
        printf("%7.0f\t%10.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}