#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
  char id; //char flagg; char length;
  //char modell[253];
}ruter;

int main(void){
  ruter* mainarray[10];
  
  for(int i=0;i<5;i++){
    ruter* temprute=malloc(sizeof(ruter)+1);
    char ide;
    printf("Enter id \n" );
     scanf("%c",&ide);
     temprute->id=ide;

     mainarray[i]=temprute;
     free(temprute);

  }
   for(int i=0;i<5;i++)
     printf("id is --: %c\n",mainarray[i]->id );
  //free(temprute);
  return 0;
}
