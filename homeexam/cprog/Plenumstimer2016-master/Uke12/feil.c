#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEI_STRING "hei inf1060"

int func3() {
	//char buf[128] = { 0 };
	char buf[128];
	strcat(buf, HEI_STRING);
	printf("%s\n", buf);
}

int func2() {
	func3();
}

int func1() {
	func2();
}

int main(void) {
	func1();
	return 0;
}
