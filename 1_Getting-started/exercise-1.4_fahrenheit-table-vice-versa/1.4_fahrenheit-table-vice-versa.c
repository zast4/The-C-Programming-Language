#include <stdio.h>

/* печать таблицы теператур по Фаренгейту
 * и цельсию для fahr = 0, 20, ..., 300; вариант с плавающей точкой */

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;  // нижняя граница таблицы температур
    upper = 300;  // верхняя граница
    step = 20;  // шаг

    fahr = lower;
    printf("Cel Fahren\n");
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}