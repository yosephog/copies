#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

#define BUF_size 512

char* read_name(void){
  char* name;
  char buf[BUF_size];
  char* newLine;
  printf("Enter a name \n");
  fgets(buf,sizeof(buf),stdin);
  newLine=strchr(buf,'\n');
  if(newLine != NULL){
    *newLine='\0';
  }
   name=malloc(strlen(buf) +1);
  strcpy(name,buf);
  return name;
}
int main(void){
  char* name;
  name=read_name();
  printf("The name is %s\n", name);
  free(name);
  return 0;
}
