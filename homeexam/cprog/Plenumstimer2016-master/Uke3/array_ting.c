#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DEBUG

/*
 * argc = argument count
 * argv = argument vector (aka. array)
 */
int main(int argc, char *argv[])
{
	char **array;

	for (int i = 0; argv[i] != NULL; i++) {
		printf("argv[%d]: %s\n", i, argv[i]);
	}

	char *bug = NULL;
	strcpy(bug, "hei");

	/* array = { "hei", "du", NULL }; */
	array = calloc(sizeof(char *), (argc + 1));
	for (int i = 0; i < argc; i++) {
#if 1
		array[i] = malloc(strlen(argv[i]) + 1);
		strcpy(array[i], argv[i]);
#else
		array[i] = strdup(argv[i]);
#endif
	}

	array[argc] = NULL;

#ifdef DEBUG
	for (int i = 0; array[i] != NULL; i++) {
		printf("array[%d]: %s\n", i, array[i]);
	}
#endif

	for (int i = 0; i < argc; i++) {
		free(array[i]);
	}
	free(array);

	return 0;
}
