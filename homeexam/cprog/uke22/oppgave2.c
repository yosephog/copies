#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
  int a=fork();
  printf("the a is %d\n",a );
  if(a){
    printf("i am a parent %d \n",a);
  }
  else{
    printf("i am a child and my pid is %d\n",getpid() );
  }
  return 0;
}
