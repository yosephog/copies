#include <stdio.h>
#include <string.h>

/*
 * type - char
 * lengde - char
 */
int main(void)
{
	/* printing av rare tegn */
	char *test = "INF1060\rer kult";
	printf("Kul tekst: %s\n", test);

	printf("Hei\rhva \b\b\bskjer?\n");

	/* */

	char *buf = "O\x0dRefrigerator.";

	printf("MESSAGE FROM SERVER: %s\n", buf+2);

	char buf2[256];
	memset(buf2, 'A', sizeof(buf2));
	memcpy(buf2, buf, strlen(buf));

	unsigned char len = buf[1];
	printf("Lengde: %u\n", len);
	printf("buf: %.*s\n", len, buf + 2);

	return 0;
}
