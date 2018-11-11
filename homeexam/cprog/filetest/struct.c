#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
   char name[32];
   unsigned int age;

}items;

int main(void){
   items* list[5];

   char mem[5];
  // memset(mem,0,sizeof(mem));
   printf(" memset %s\n",mem );

/**
   for(int i=0;i<2;i++){
      list[i]=malloc(sizeof(items));
      items* person=list[i];

      printf("Enter name\n");
      char names[32];
      scanf("%s",names);
      strcpy(person->name,names);
      printf("enterd name %s\n",person->name );
   }
   for(int i=0;i<2;i++){
     printf("%s\n",list[i]->name );
   }**/
  return 0;
}
