/*
 * sizeof vs strlen
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	/* lengden = 9 + 1 */
	char *text = "en string";
	char *copy;

	//copy = malloc(sizeof(text));
	copy = malloc(strlen(text) + 1);
	strcpy(copy, text);

	printf("copy: %s\n", copy);

	free(copy);

	return 0;
}

