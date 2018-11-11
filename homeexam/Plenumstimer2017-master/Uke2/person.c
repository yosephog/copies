#include <stdio.h>
#include <stdlib.h>

struct person {
    int age;
    char initial;
    char initial2;
};

void init_person(struct person *p, int age, char initial) {
    p->age = age;
    p->initial = initial;
    p->initial2 = initial;
}

void funksjon(struct person p) {
    printf("Alder: %d\n", p.age);
    printf("Alder: %c\n", p.initial);
    printf("Adressen til Alder: %p\n", (void*)&p.age);
    printf("Adressen til Alder: %p\n", (void*)&(p.age));
    printf("Adressen til Alder: %p\n", (void*)&p);
    printf("Adressen til initial: %p\n", (void*)&p.initial);
    printf("Adressen til initial: %p\n", (void*)&p.initial2);
    p.age = 10000;
}

int main(void) {
    struct person p;
    init_person(&p, 100, 'H');
    funksjon(p);
    printf("%d\n", p.age);

    return EXIT_SUCCESS;
}
