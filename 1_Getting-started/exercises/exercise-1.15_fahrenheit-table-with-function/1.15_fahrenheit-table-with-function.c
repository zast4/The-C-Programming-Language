#include <stdio.h>

/* печать таблицы теператур по Фаренгейту
 * и цельсию для fahr = 0, 20, ..., 300; вариант с плавающей точкой */

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