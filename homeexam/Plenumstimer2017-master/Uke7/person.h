#ifndef __PERSON_H
#define __PERSON_H

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int age;
    char name[32];
    char gender;
} person_s;

person_s *create_person(int age, char name[], char gender);
void print_person(person_s *p);

#endif
