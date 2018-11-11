#include<stdio.h>
#include<stdlib.h>

struct person{
   char* name;
   unsigned int age;
};
void set_age(struct person* p,unsigned int a){
   p->age=a;
}
int get_age(struct person* p){
  return p->age;
}
void set_name(struct person* p,char* namee){
  if(*namee==0) // or if(name[0]==0)
    printf("can't leave empty \n" );
   p->name=namee;
}
char* get_name(struct person* p){
  return p->name;
}
struct person* init(void){
   return malloc(sizeof(struct person));
}
int main(void){
  struct person* yoseph=malloc(sizeof(struct person));
  struct person* eph=init();
  set_name(yoseph,"ephreog ");
  set_age(yoseph,33);
  set_name(eph,"yoseph");
  set_age(eph,33);

  printf("%s : %d \n",get_name(yoseph),get_age(yoseph));
  printf("%s : %d \n",eph->name,eph->age );
  free(yoseph);
  return 0;
}
