#include <stdio.h>
#include <stdlib.h>

char* read_user() { 
    int read_size;
    char buf[64];

    printf("Skriv lengden på det du vil skrive: ");
    fgets(buf, sizeof(buf), stdin);
    read_size = atoi(buf) + 1;

    char *s = malloc(read_size);

    printf("Skriv det:\n");
    fgets(s, read_size, stdin);

    return s;
}

int main(void) {
    char *s = read_user();
    printf("%s\n", s);
    printf("%s\n", s+4);
    free(s);
}
