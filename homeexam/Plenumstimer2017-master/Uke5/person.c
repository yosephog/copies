#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    int age;
    char name[32];
    char gender;
} person_s;

person_s *create_person(int age, char name[], char gender) {
    person_s *p = malloc(sizeof(person_s));

    p->age = age;
    p->gender = gender;
    strncpy(p->name, name, sizeof(p->name));
    p->name[sizeof(p->name) - 1] = '\0';

    return p;
}

int main(void) {
    char user_reply_buffer[64] = { 0 };

    printf("Create new person? [y/n]\n");

    fgets(user_reply_buffer, sizeof(user_reply_buffer), stdin);
    user_reply_buffer[strlen(user_reply_buffer) - 1] = '\0';

    person_s *p;
    if(user_reply_buffer[0] == 'y') {

        printf("Person creation:\nGive name: ");
        fgets(user_reply_buffer, sizeof(user_reply_buffer), stdin);

        p = create_person(24, user_reply_buffer, 'M');
        printf("gender: %c\n", p->gender);
    } else {
        printf("ikke her\n");
    }

    free(p);

    return EXIT_SUCCESS;
}
