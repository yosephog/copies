#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int isint(char* str){
  for(unsigned int i=0; i<strlen(str);i++){
    printf("%d : %c\n",i,str[i] );
    if(str[i]>='0' && str[i]<='9'){
      continue;
    }
    else
      return 0;
  }
  return 1;
}
int isint2(char* str){
  long int num;
  char* end; // point to a pointer strtol(char* ,char**,tall system(10))
  num=strtol(str,&end,10);
  if(end[0] == '/0'){
    return 1;
  }
  return 0;
}
int main( int argc,char* argv[]){
  char* msg;
  int tall;
  if(argc < 2){
    printf("Usage: %s <argument required> \n", argv[0]);
    return 0;
  }
  msg=argv[1];

  printf("the first argument is %s \n",msg );
  tall=isint(msg);
  if(isint(msg)==1){
    printf("det er et tall \n");
  }


  return 0;
}
