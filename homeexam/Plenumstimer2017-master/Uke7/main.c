#include "person.h"

extern char** environ;

int main(void) {
    char user_reply_buffer[64] = { 0 };

    printf("Create new person? [y/n]\n");

    fgets(user_reply_buffer, sizeof(user_reply_buffer), stdin);

    person_s *p = NULL;
    if(user_reply_buffer[0] == 'y') {

        printf("Person creation:\nGive name: ");
        fgets(user_reply_buffer, sizeof(user_reply_buffer), stdin);
        char* name = strdup(user_reply_buffer);
        name[strlen(name)-1] = '\0'; //trims newline

        long int age;
        char* endptr;
        do {
            printf("Give age: ");
            fgets(user_reply_buffer, sizeof(user_reply_buffer), stdin);
            age = strtol(user_reply_buffer, &endptr, 10);
            if (age == 0 && endptr == (char*)&user_reply_buffer) {
                printf("Please provide a number!\n");
            } else {
                break;
            }
        } while(1);

        printf("Give gender (one letter): ");
        fgets(user_reply_buffer, sizeof(user_reply_buffer), stdin);
        char gender = user_reply_buffer[0];

        p = create_person(age, name, gender);
        free(name);
    } else {
        while(*environ) {
            printf("environ: %s\n", *environ);
            environ++;
        }
    }

    int ret = fork();
    if(ret) {
        printf("Hei, jeg er pappa, mitt barn er %d\n", ret);
        printf("Forresten, min pid er %d\n", getpid());
        if(p) {
            free(p);
        }
        int status;
        wait(&status);
        printf("Barnets status: %d\n", status);
    } else {
        printf("Jeg er barn c:) \n");
        printf("Forresten, min pid er %d\n", getpid());
        if(p) {
            print_person(p);
            free(p);
        }
        return EXIT_FAILURE;
    }

    printf("Hei nå dør jeg :(\n");

    printf("Oppgi ID for ny ruter: ");
    int ruter_id;
    scanf("%d", &ruter_id);
    int c;
    while ( (c = getchar()) != '\n' && c != EOF ) { }

    printf("Oppgi navn for ny ruter: ");
    char navn[256];
    scanf("%256s", navn);

    printf("ID lest: %d\n", ruter_id);
    printf("navn lest: %s\n", navn);

    return EXIT_SUCCESS;
}
