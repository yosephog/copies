#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int *tall_array;
	int tall[] = { 1, 2, 3, 4, 5 };

	tall_array = malloc(5 * sizeof(int));
	for (int i = 0; i < 5; i++) {
		tall_array[i] = tall[i];
	}

	for (int i = 0; i < 5; i++) {
		printf("tall_array[%d]: %d\n", i, tall_array[i]);
	}

	char **str_array = malloc(argc * sizeof(char *));
	for (int i = 0; i < argc; i++) {
		str_array[i] = malloc(strlen(argv[i]) + 1);
		strcpy(str_array[i], argv[i]);
	}

	for (int i = 0; i < argc; i++) {
		printf("str_array[%d]: %s\n", i, str_array[i]);
		free(str_array[i]);
	}

	free(tall_array);
	free(str_array);

	return 0;
}
