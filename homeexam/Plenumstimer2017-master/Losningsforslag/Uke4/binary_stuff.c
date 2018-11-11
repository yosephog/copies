#include <stdio.h>
#include <limits.h>
#include "util.h"

int main(void)
{
	print_binary(42);
	print_binary(3);
	print_binary(42 & 3);

	printf("\nMasking\n");
	print_binary(0xff);
	print_binary(159712547);
	print_binary(159712547 & 0xff);

	printf("\n");
	print_binary(0xff00);
	print_binary(159712547);
	print_binary((159712547 & 0xff00) >> 8);

	printf("\n");
	print_binary(0x10);
	print_binary(159712547);
	print_binary(159712547 & 0x10);
	int a = 159712547 | 0x10;
	printf("\n");
	print_binary(a);
	print_binary(0x10);
	print_binary(a & 0x10);

	printf("\nShifting\n");
	print_binary(42);
	print_binary(42 << 1);
	print_binary(100 >> 1);

	printf("\nSet bit\n");
	print_binary(42);
	print_binary(1 << 8);
	print_binary(42 | (1 << 8));

	printf("\nBit flipping\n");
	print_binary(42);
	print_binary((~42) + 1);

	printf("\n");
	print_binary(-1);
	print_binary(INT_MAX);

	printf("\n");
	print_binary(0);
	print_binary(-1);
	print_binary(-2);
	print_binary(-3);
	print_binary(-4);
	print_binary(-5);

	printf("\nClear bits\n");
	print_binary(-1);
	int mask = 1 << 8;
	print_binary(mask);
	print_binary(~mask);
	print_binary(~mask & -5);

	return 0;
}
