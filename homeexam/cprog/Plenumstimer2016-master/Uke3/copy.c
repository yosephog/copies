#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *en = "hei";
	char *to = "du";

	char *ny = malloc(strlen(en) + strlen(to) + 1);
	strcpy(ny, en);
	strcat(ny, to); /* string concatenate */

	printf("%s\n", ny);

	free(ny);

	return 0;
}
