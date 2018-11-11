#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return 0;
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL) {
		fprintf(stderr, "Couldn't open file: %s\n", argv[1]);
		return -1;
	}

	int num;
	printf("1: %d\n", fgetc(file));
	printf("2: %d\n", fgetc(file));

	fread(&num, sizeof(num), 1, file);
	printf("Num: %d\n", num);

	fclose(file);

	return 0;
}
