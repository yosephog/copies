#include "person.h"

void print_person(person_s *p) {
    printf("----------------------------\n");
    printf("PERSON INFO\n");
    printf("Name:    %s\n", p->name);
    printf("Age:     %d\n", p->age);
    printf("Gender:  %c\n", p->gender);
    printf("----------------------------\n");
}

person_s *create_person(int age, char name[], char gender) {
    person_s *p = malloc(sizeof(person_s));

    p->age = age;
    p->gender = gender;
    strncpy(p->name, name, sizeof(p->name));
    p->name[sizeof(p->name) - 1] = '\0';

    return p;
}
