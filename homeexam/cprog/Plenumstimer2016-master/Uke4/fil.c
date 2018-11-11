#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return 0;
	}

	FILE *fil = fopen(argv[1], "r");
	if (fil == NULL) {
		fprintf(stderr, "Couldn't open file: %s\n", argv[1]);
		return -1;
	}

	int line = 0;
	char buf[256];
	char* buf2 = &buf[0];
	//char* buf3 = malloc(256);

	while (fgets(buf, 256, fil) != NULL) {
		printf("line %d: %s", line, buf);
		line++;
	}

	fclose(fil);

	return 0;
}
