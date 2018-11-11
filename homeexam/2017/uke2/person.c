#include <stdio.h>
#include <stdlib.h>

struct person{
  int age;
};
void init_person(struct person* p,int age){
//  (*p).age=age;
  p->age=age;
}
void funksjon(struct person* p){
  printf("age is %d \n",p->age);
}
int main(void){
  struct person p;
  init_person(&p,10);
  funksjon(&p);
  return 0;
}
