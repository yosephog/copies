#include <stdio.h>

int main(void)
{
	char i;
	int sum = 0;

	for (i = 0; i < 255; i++) {
		printf("i: %d\n", i);
		sum += i;
	}

	printf("sum: %d\n", sum);

	return 0;
}
