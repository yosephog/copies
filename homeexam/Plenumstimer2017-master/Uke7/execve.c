#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[], char* envp[]) {

    printf("Hei\n");
    if(!fork()) {
        execve(argv[1], &argv[1], NULL);
    }
    printf("Hei\n");

}

