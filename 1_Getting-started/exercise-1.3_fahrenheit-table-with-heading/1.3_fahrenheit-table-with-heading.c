#include <stdio.h>

/* печать таблицы теператур по Фаренгейту
 * и цельсию для fahr = 0, 20, ..., 300; вариант с плавающей точкой */

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