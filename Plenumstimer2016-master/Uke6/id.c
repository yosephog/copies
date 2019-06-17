#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return 0;
	}

	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		perror("fopen()");
		exit(EXIT_FAILURE);
	}

	unsigned char id = fgetc(fp);
	printf("ID: %u (0x%x)\n", id, id);

	fclose(fp);
	return 0;
}
