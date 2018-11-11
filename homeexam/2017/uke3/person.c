#include <stdio.h>
#include <stdlib.h>
#include "person.h"

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
int person_set_name(struct person* p, char*s) {
	if (s == NULL || *s == '\0') { // (void*) NULL
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
	return calloc(1, sizeof(struct person));
}

