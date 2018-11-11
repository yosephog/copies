#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
void tolowercase(char s[]) {
	printf("%s\n", s);
	int i = 0;
	while(s[i]) {
		printf("%c\n", s[i]);
		if(s[i] <= 90) {
			s[i] += 32;
		}
		i++;
	}
}
#else
void tolowercase(char* s) {
	printf("%s\n", s);
	while(*s) {
		printf("%c\n", *s);
		if(*s <= 90) {
			*s += 32;
		}
		s++;
	}
}
#endif

int main() {
	char* s = malloc(4);
	strcpy(s, "ABC");

	tolowercase(s);

	printf("%s\n", s);
}

