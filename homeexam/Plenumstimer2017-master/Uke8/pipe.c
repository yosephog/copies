#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void child(int pipe_fd[2]);
void parent(int pipe_fd[2]);

#define MSG "Hei fra ditt barn"

int main() {
    int pipe_fd[2];

    if(pipe(pipe_fd) == -1) {
        perror("Pipe creation");
        exit(1);
    }

    if(fork()) {
        parent(pipe_fd);
    } else {
        child(pipe_fd);
    }
    return EXIT_SUCCESS;
}

/* The child process
 */
void child(int pipe_fd[2]) {
    int write_end = pipe_fd[1];
    close(pipe_fd[0]);

    char buf[500000] = { 0 };
    FILE* file = fopen("img", "r");
    size_t file_size = fread(buf, 1, 500000, file);
    while(1) {
       // fgets(buf, sizeof(buf), stdin);

        unsigned int ret;

        //size_t str_len = strlen(buf);
        ret = write(write_end, &file_size, sizeof(size_t));
        if (ret != sizeof(size_t)) {
            fprintf(stderr, "ERROR IN WRITE!!! ABORTING\n");
            exit(1);
        }
        ret = write(write_end, buf, file_size);
        if (ret != strlen(buf)) {
            fprintf(stderr, "ERROR IN WRITE!!! ABORTING\n");
            exit(1);
        }

        if(strcmp(buf, "exit\n") == 0) {
            close(write_end);
            break;
        }
    }
}

/* The parent process
 */
void parent(int pipe_fd[2]) {
    int read_end = pipe_fd[0];
    close(pipe_fd[1]);

    size_t recv_len;
    char buf[512] = { 0 };
    while(1) {
        unsigned int bytes_read = read(read_end, &recv_len, sizeof(size_t));
        if(bytes_read == 0) {
            break;
        }
        if (bytes_read != sizeof(size_t)) {
            fprintf(stderr, "ERROR when reading recv size!!! ABORTING\n");
            exit(1);
        }
        
        bytes_read = read(read_end, buf, sizeof(buf));
        if(bytes_read == 0) {
            break;
        }
        if (bytes_read != recv_len) {
            fprintf(stderr, "ERROR IN READ!!! ABORTING\n");
            exit(1);
        }

        buf[bytes_read] = '\0';
        printf("%s\n", buf);
    }
}
