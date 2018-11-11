#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 1060;
    printf("Hello INF%08p!\n", NULL);

    char s[10];
    char *x = malloc((sizeof(char)) * 10);

    printf("%d\n", sizeof(s));
    printf("%d\n", sizeof(x));

    return 0;
}

