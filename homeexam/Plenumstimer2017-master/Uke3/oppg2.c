#include <stdio.h>

int main(void) {
    int i;
    int arr[] = {2, 1, -1, 10, 22, 21};
    int arrlen = 6;

    printf("Array:\n");
    for(i = 0; i < arrlen; i++) {
        printf("[%d]: %d\n", i, arr[i]);
    }

    printf("Pekere:\n");
    for(i = 0; i < arrlen; i++) {
        printf("%p\n", (void*)(arr + i));
        printf("[%d]: %d\n", i, *(arr + i));
    }
}
