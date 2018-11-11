#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void usage(char* argv[]) {
    printf("Usage: %s message\n", argv[0]);
    exit(EXIT_SUCCESS);
}

int check_number(char *argv) {
    
    int i = 0;
    while(argv[i]) {
        if(!isxdigit(argv[i])) {
            return 0;
        }
        i++;
    }

    return 1;
}

char strgetc(char* s, int pos) {
    return s[pos];
}

int main(int argc, char* argv[]) {
    printf("programnavn: %s\n", argv[0]);
    printf("antall arg: %d\n", argc);

    if (argc < 2) {
        usage(argv);
    }

    char *msg = argv[1];

    printf("msg[%d]: %c\n", 300000, strgetc(msg, 300000));

    int num;
    if(check_number(msg)) {
        num = strtol(argv[1], NULL, 16);
        printf("number: %d\n", num);
    } else {
        printf("input: %s\n", msg);
    }

    return EXIT_SUCCESS;
}
