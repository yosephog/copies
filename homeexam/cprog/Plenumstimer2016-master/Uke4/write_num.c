#include <stdio.h>
#include <stdlib.h>

/*
 * argc = argument count
 * argv = argument vector (aka. array)
 */
int main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <filename> <number>\n", argv[0]);
		return 0;
	}

	FILE *file = fopen(argv[1], "w+");
	if (file == NULL) {
		fprintf(stderr, "Couldn't open file: %s\n", argv[1]);
		return -1;
	}

	char test[2] = {4, 2};
	fwrite(&test[0], 2, 1, file);

	/* TODO: bytt til strtol!!! */
	int num = atoi(argv[2]);
	fwrite(&num, sizeof(int), 1, file);

	fclose(file);

	return 0;
}
