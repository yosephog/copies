#include <stdio.h>

int main(void) {
    int i, j;
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arrlen = 3;

    printf("Array:\n");
    for(i = 0; i < arrlen; i++) {
        for (j = 0; j < arrlen; j++) {
            printf("[%d][%d]: %d\n", i, j, arr[i][j]);
        }
    }

    printf("Pekere:\n");
    for(i = 0; i < arrlen; i++) {
        for (j = 0; j < arrlen; j++) {
            int *row_pointer = *(arr + i);
            printf("[%d][%d]: %d\n", i, j, *(row_pointer + j));
            //arr = {{x, x, x, ...}, ...}
            //arr[0] = {x, x, x, ...}
            //arr[0][0] = x;
        }
    }
}
