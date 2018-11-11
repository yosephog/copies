#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * int - number of items, ends with \n
 *
 * items:
 *	name, ends with \n	(max 256 bytes)
 *	price, ends with \n (int)
 *	id, ends with \n	(char)
 *
 *
 *	1. struct
 *	2. les ut data
 *	3. map / array med structer
 */

struct item {
	char name[256];
	int price;
	unsigned char id;
};

struct item *items[257]; /* 256 + NULL pointer */

/*
 * Read an int from a file stream.
 *
 * 
 * @fp		file stream
 * @ptr		store int here
 */
void read_int(FILE *fp, int *ptr)
{
	fread(ptr, sizeof(int), 1, fp);
}

void check_newline(FILE *fp)
{
	/* newline = '\n' = 0xa = 10 */
	int c = fgetc(fp);
	if (c != '\n') {
		fprintf(stderr, "Expected newline, got 0x%x (%d)\n", c, c);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
}

void strip_newline(char *s)
{
	char *ptr = strchr(s, '\n');
	if (ptr != NULL)
		*ptr = '\0';
}

void print_item(struct item *item)
{
	printf("ID: %d\n", item->id);
	printf("Name: %s\n", item->name);
	printf("Price: %d\n", item->price);
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return 0;
	}

	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		perror("fopen()");
		exit(EXIT_FAILURE);
	}

	int num_items;
	read_int(fp, &num_items);
	printf("Number of items: %d\n", num_items);
	check_newline(fp);

	items[num_items] = NULL;

	for (int i = 0; i < num_items; i++) {
		char name[256];
		memset(name, 0, sizeof(name));
		fgets(name, sizeof(name), fp);
		strip_newline(name);

		int price;
		read_int(fp, &price);

		check_newline(fp);
		//int id = fgetc(fp);
		unsigned char id;
		fread(&id, sizeof(unsigned char), 1, fp);
		check_newline(fp);

		items[i] = malloc(sizeof(struct item));
		struct item *item = items[i];
		strcpy(item->name, name);

		item->price = price;
		item->id = id;
		print_item(item);
	}

	for (int i = 0; items[i] != NULL; i++) {
		free(items[i]);
	}

	fclose(fp);

	return 0;
}
