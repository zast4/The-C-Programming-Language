#include <stdio.h>

/* Rewrite the temperature conversion program of Section 1.2
 * to use a function for conversion. */

float fahr_to_cels(float fahr);

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;  // нижняя граница таблицы температур
    upper = 300;  // верхняя граница
    step = 20;  // шаг

    fahr = lower;
    while (fahr <= upper) {
        celsius = fahr_to_cels(fahr);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}

float fahr_to_cels(float fahr) {
    return (5.0 / 9.0) * (fahr - 32);
}