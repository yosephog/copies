#include <stdio.h>


void print_binary(int num)
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

int main(void) {

    printf("And:\n");
    print_binary(10);
    print_binary(15);
    print_binary(10 & 15);
    print_binary(10 && 15);
    print_binary(0 && 0);

    printf("Not:\n");
    print_binary(10);
    print_binary(~10);

    printf("Or:\n");
    print_binary(10);
    print_binary(24);
    print_binary(10 | 24);

    printf("Xor:\n");
    print_binary(10);
    print_binary(24);
    print_binary(10 ^ 24);

    printf("Shift Left\n");
    print_binary(11);
    print_binary(11 << 10);

    printf("Shift Right\n");
    print_binary(11264);
    print_binary(11264 >> 8);
    
    int mask = 255;
    int mask2 = 255 << 8;

    printf("Masking:\n");
    print_binary(231728939);
    print_binary(mask);
    print_binary(mask2);
    print_binary(mask & 231728939);
    print_binary(mask2 & 231728939);

    int flagg = 12379832;

#define wifi_bit_num 2
#define wifi_bit_mask (1<<32-wifi_bit_num)

    print_binary(flagg);
    print_binary(wifi_bit_mask);
    print_binary(flagg | wifi_bit_mask);

    flagg |= wifi_bit_mask;
     
    if(flagg & wifi_bit_mask) {
        printf("hei\n");
    }

    print_binary(flagg & ~wifi_bit_mask);

}

