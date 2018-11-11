#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
  char* text="en string";
  char* copy=malloc(sizeof(char*) * strlen(text)+1);
  strcpy(copy,text);
  printf("the copy is %s\n",copy );
  free(copy);
  return 0;
}
