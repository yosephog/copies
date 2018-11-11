#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readName(){
  char name[32];
  char* name2= (char*) malloc(sizeof(char) * sizeof(name));
  strcpy(name,"yoseph");
  strcpy(name2,"yoseph");
  return name2;
}
char* read_user(){
  char buf[64];
  int read_size;
  printf("Enter size \n" );
  fgets(buf,sizeof(buf)-1,stdin);
  read_size=atoi(buf);
  char* s=(char *) malloc(sizeof(char) * read_size);
  printf("Enter name\n");
  fgets(s,sizeof(s)-1,stdin);
  return s;

}

char* read_file(char* filename){

  char buf[64];
  int read_size;
  printf("Enter the size of file\n");
  fgets(buf,sizeof(buf)-1,stdin);
  read_size=atoi(buf);
  char* myfile=(char*) malloc(sizeof(char*) * read_size);
  FILE* fp=fopen(filename,"r");
  fgets(myfile,sizeof(buf)-1,fp);
  return myfile;
}

int main(void){
  char* txt="hello world";
  char arr[5];
  strncpy(arr,txt,sizeof(arr)-1);
  printf("%s\n",arr );
  char* na=readName();
  printf("%s\n",na );
  char* name=read_user();
  printf("The name you enterd is -: %s\n",name );
  free(na);
  free(name);
}
