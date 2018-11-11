#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isint(char *str);
int isint2(char *str);

/*
 * argc = argument count
 * argv = argument vector (aka. array)
 */
int main(int argc, char *argv[])
{
	char *msg;
	int tall;

	if (argc != 2) {
		printf("Usage: %s <message>\n", argv[0]);
		return 0;
	}

	printf("antall argumenter: %d\n", argc);
	printf("argv[0]: %s\n", argv[0]);

	msg = argv[1];
	printf("Input: %s\n", msg);
	if (isint2(msg) == 1) {
		printf("er et tall :)\n");
		tall = atoi(msg);
		printf("tall: %d\n", tall);
	} else {
		printf("er ikke et tall :C\n");
	}

	return 0;
}

int isint(char *str)
{
	printf("strlen(str): %zu\n", strlen(str));

	for (int i = 0; i < strlen(str); i++) {
		printf("%d: %c\n", i, str[i]);
		if (str[i] >= '0' && str[i] <= '9') {
			continue;
		}

		return 0;
	}

	return 1;
}

int isint2(char *str)
{
	char *end;
	long int num;

	num = strtol(str, &end, 10);
	if (end[0] == '\0')
		return 1;
	return 0;
}
