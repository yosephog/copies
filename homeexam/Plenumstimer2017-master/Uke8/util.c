#include "util.h"

void print_binary_char(char num)
{
	int pos = (sizeof(char) * 8) - 1;
	printf("%10d: ", num);

	for (int i = 0; i < (int)(sizeof(char) * 8); i++) {
		char c = num & (1 << pos) ? '1' : '0';
		putchar(c);
		if (!((i + 1) % 8))
			putchar(' ');
		pos--;
	}
	putchar('\n');
}

void print_binary_int(int num)
{
	int pos = (sizeof(int) * 8) - 1;
	printf("%10d: ", num);

	for (int i = 0; i < (int)(sizeof(int) * 8); i++) {
		char c = num & (1 << pos) ? '1' : '0';
		putchar(c);
		if (!((i + 1) % 8))
			putchar(' ');
		pos--;
	}
	putchar('\n');
}
