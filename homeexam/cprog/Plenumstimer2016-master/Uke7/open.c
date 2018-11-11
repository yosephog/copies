#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 4000000000LLU

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return 0;
	}

	// FILE *fp = fopen(filename, "w+");
	int flags = O_WRONLY | O_CREAT | O_TRUNC;
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	int fd = open(argv[1], flags, mode);
	if (fd == -1) {
		perror("open()");
		exit(EXIT_FAILURE);
	}

	printf("Yay\n");
	char *buf = "Hello, world! :)\n";

	ssize_t ret;
	size_t sum = 0;

	do {
		ret = write(fd, buf + sum, strlen(buf));
		sum += ret;

		if (ret == -1) {
			perror("write()");
			close(fd);
			exit(EXIT_FAILURE);
		}
	} while (sum != strlen(buf));

	printf("Wrote %zd bytes!\n", sum);

	close(fd);

	return 0;
}
