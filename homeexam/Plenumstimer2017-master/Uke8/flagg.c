#include <stdio.h>
#include <string.h>

#include "util.h"

#define WIFI_BIT_POSITION 2
#define GHZ_BIT_POSITION 3

/* This macro sets the byte at positon n in byte b to 1
 *
 * Input:
 *     n: the bit number (from the right)
 *     b: the byte to work on
 *
 * Return: none
 */
#define BYTE_SET_BIT(n, b) (b = b | 1 << n)

#define BYTE_UNSET_BIT(n, b) (b &= ~(1 << n))
#define BYTE_FLIP_BIT

#define FLAGG_SET_WIFI(flagg) (flagg = flagg | 1 << 2)

#define FLAGG_SET_WIFI_IMPROVED(flagg) (BYTE_SET_BIT(WIFI_BIT_POSITION, flagg))

#define STREQ(s1, s2) (!strcmp(s1, s2))

#define STRNEQ(s1, s2) (!STREQ(s1, s2))

char set_wifi(char flagg) {
    return flagg | 1 << 2;
}

int main() {
    char flagg = 54;
    print_binary_int((int)flagg);
    print_binary_char(flagg);

    BYTE_SET_BIT(7, flagg);
    print_binary_int((int)flagg);
    print_binary_char(flagg);

    char flagg2 = 0;

    print_binary_char(flagg2);
    FLAGG_SET_WIFI(flagg2);
    print_binary_char(flagg2);

    flagg2 = 0;

    print_binary_char(flagg2);
    FLAGG_SET_WIFI_IMPROVED(flagg2);
    print_binary_char(flagg2);


    if (!strcmp("hei", "hei")) {
        printf("Like!\n");
    }

    if (STREQ("hei", "hei")) {
        printf("like!\n");
    }

}
