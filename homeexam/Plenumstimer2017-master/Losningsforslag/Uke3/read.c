#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

#define BUF_SIZE 512

char *read_name(void)
{
	char *name;
	char *newline;
	char buf[BUF_SIZE];

	printf("Skriv inn navn: ");
	fgets(buf, BUF_SIZE, stdin);

	newline = strchr(buf, '\n');
	if (newline != NULL) {
		*newline = '\0';
	}

	name = malloc(strlen(buf) + 1);
	strcpy(name, buf);

	return name;
}

int read_age(void)
{
	int age;
	
	printf("Skriv inn alder: ");
	scanf("%d", &age);

	return age;
}

int main(void)
{
	int age;
	char *name;

	name = read_name();
	printf("name: %s\n", name);

	age = read_age();
	printf("age: %d\n", age);

	struct person* christian = person_init();

	person_set_name(christian, name);
	printf("%s\n", person_get_name(christian));

	char* name_static = "Christian";
	christian->name = name_static;

	free(name);
	free(christian);

	return 0;
}

