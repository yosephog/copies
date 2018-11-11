#include <stdio.h>
#include <stdlib.h>

struct person {
	char* name;
	unsigned int age;
};

int person_get_age(struct person* p) {
	return p->age;
}

int person_set_age(struct person* p, int new_age) {
	if(new_age < 0) {
		return 0;
	}
	p->age = new_age;
	return 1;
}

char* person_get_name(struct person* p) {
	return p->name;
}

/*
 * returns 1 on success
 */
int person_set_name(struct person* p, char* s) {
	if (*s == NULL) {
		return 0;
	}

	p->name = s;
	return 1;
}

int person_check_valid(struct person* p) {
	if (p->name == NULL) {
		return 0;
	} else if (p->age > 120) {
		return 0;
	}
	return 1;
}

struct person* person_init(void) {
	//struct person HansPetter;
	//return &HansPetter;  //UNSAFE
	return malloc(sizeof(struct person));
}

int main(void) {
    struct person* HansPetter = person_init();

//	unsigned int test = -1;
//	printf("%u\n", test);

	int* a = malloc(sizeof(int));
	*a = 12345;
	free(a);

	if(!person_set_age(HansPetter, 23)) {
		printf("Error: Kunne ikke sette alder til 23\n");
	}
	if(!person_set_age(HansPetter, -1)) {
		printf("Error: Kunne ikke sette alder til -1\n");
	}

	if(!person_set_name(HansPetter, "")) {
		printf("Error: Kunne ikke sette navn til \"\"\n");
	}

	if(!person_set_name(HansPetter, "Hans Petter")) {
		printf("Error: Kunne ikke sette navn til Hans Petter\n");
	}

	printf("Navn: %s, Alder: %d\n", HansPetter->name, HansPetter->age);

	free(HansPetter);
	return 0;
}

