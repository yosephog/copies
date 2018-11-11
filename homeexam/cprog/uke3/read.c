#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "person.h"

#define BUF_SIZE 512

char* read_name(void){
  char buf[BUF_SIZE];
  char* newline;
  printf("Enter a name \n" );
  fgets(buf,BUF_SIZE,stdin);
  newline=strchr(buf,'\n');
  if(newline != NULL){
    *newline='\0';
  }
  char* name=malloc(strlen(buf)+1);
  strcpy(name,buf);
  return name;
}
int read_age(void){
  int age=0;
  printf("Enter age \n" );
  scanf("%d",&age);
  return age;
}
int main(void){
 char* name=read_name();
 printf("the name %s\n",name );
 printf("the age is %d \n",read_age());

 struct person* yoseph=init();
 set_name(yoseph,name);
 printf("person name %s\n", get_name(yoseph));

 //free(yoseph->name);
 free(name);
 free(yoseph);
  return 0;
}
