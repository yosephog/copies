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
	int flags = O_WRONLY | O_CREAT;
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	int fd = open(argv[1], flags, mode);
	if (fd == -1) {
		perror("open()");
		exit(EXIT_FAILURE);
	}

	printf("Yay\n");
	char *buf = "Hello, world! :)\n";
	char *sinnsykt_stor_buf = malloc(BUF_SIZE);
	if (sinnsykt_stor_buf == NULL) {
		perror("malloc()");
		close(fd);
		exit(EXIT_FAILURE);
	}

	memset(sinnsykt_stor_buf, 'A', BUF_SIZE);

	ssize_t ret = write(fd, sinnsykt_stor_buf, BUF_SIZE);
	if (ret == -1) {
		perror("write()");
		close(fd);
		exit(EXIT_FAILURE);
	}

	if (ret != BUF_SIZE) {
		printf("huff :(\n");
	}

	printf("Wrote %zd bytes!\n", ret);

	close(fd);

	return 0;
}
