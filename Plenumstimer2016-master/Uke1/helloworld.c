#include <stdio.h>

int main(void)
{
	char a = 'a';
	char *b = &a;
	char *c = b;
	char *d = c;

	printf("**c: %c\n", *c);
	printf("**c: %x\n", *c);
	printf("**d: %c\n", *d);

	return 0;
}
