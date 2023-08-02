#include <stdio.h>
#include <stdlib.h>

void output(int *matrix, int row, int col);

int main(void) {
    int row, col;
    scanf("%d %d", &row, &col);
    int *matrix = calloc(row * col, sizeof(int)); 

    int i = 0, j = 0;
    int count = 1;
    while (count < row * col) {
        while (j < (col - 1) && *(matrix + i * col + (j + 1)) == 0 && count < row * col) {
            *(matrix + i * col + j) = count;
            j++;
            count++;
        }

        while (i < (row - 1) && *(matrix + (i + 1) * col + j) == 0 && count < row * col) {
            *(matrix + i * col + j) = count;
            i++;
            count++;
        }

        while (j > 0 && *(matrix + i * col + (j - 1)) == 0 && count < row * col) {
            *(matrix + i * col + j) = count;
            j--;
            count++;
        }

        while (i > 0 && *(matrix + (i - 1) * col + j) == 0 && count < row * col) {
            *(matrix + i * col + j) = count;
            i--;
            count++;
        }
    }
    *(matrix + i * col + j) = count;

    output(matrix, row, col);
    return 0;
}

void output(int *matrix, int row, int col) {
    for (int i_out = 0; i_out < row; i_out++) {
        for (int j_out = 0; j_out < col; j_out++) {
            printf("%d ", *(matrix + i_out * col + j_out));
        }
        printf("\n");
    }
}