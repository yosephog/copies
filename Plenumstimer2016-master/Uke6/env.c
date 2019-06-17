#include <stdio.h>

extern char **environ;

/*
 * argc = argument count
 * argv = argument vector
 * environ = environment pointer
 */
int main(void)
{
	for (int i = 0; environ[i] != NULL; i++) {
		printf("environ[%d]: %s\n", i, environ[i]);
	}

	return 0;
}
