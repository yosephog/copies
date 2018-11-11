#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i, j, row, cell;
    int row_count = 3;
    int cells_per_row = 3;
    int *array = malloc(sizeof(int) * row_count * cells_per_row);

    FILE *output_file = fopen("out.txt", "w");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            int* local = array + (i * cells_per_row);
            local += j;
            *local = i * cells_per_row + j;
        }
    }


    fwrite(array, sizeof(int), row_count*cells_per_row, output_file);
    for (row = 0; row < 3; row++) {
        for (cell = 0; cell < 5; cell++) {
            int number = array[row * cells_per_row + cell];
            fprintf(stdout, "[%d][%d]: %d\n", row, cell, number);
//            fprintf(output_file, "[%d][%d]: %d\n", row, cell, number);
        }
    }

    fclose(output_file);
    free(array);
    array[2] = 123;

}
