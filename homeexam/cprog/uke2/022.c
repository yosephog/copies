#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char strget(char st[],unsigned int pos){
    char index;
    for(unsigned int i=0;i<strlen(st);i++){
      if(i==pos){
        index=st[i];
        break;
      }
    }
    return index;
}

int main(void){
   printf("the value  is %c\n",strget("yoseph",3) );
  /**
   if(argc < 2){
     printf("usage <need argument for > %s\n",argv[0] );
     return 0;
   }
   int numbers[]={1,2,3,4};
   int* numbers2=malloc(sizeof(int) * 4);

    for(int i=0;i< 4;i++){
        numbers2[i]=numbers[i];
        printf("tall : %d \n",numbers2[i] );
    }
   char** tall=malloc (sizeof(char *) * argc);

   for(int i=0;i<argc;i++){
     tall[i]=malloc(strlen(argv[i]) + 1);
      strcpy(tall[i],argv[i]);
   }
   for(int i=0;i<argc;i++){
     printf("the value tall[%d] is : %s\n",i,tall[i] );
   }
   free(numbers2);
   free(tall);
   **/
  return 0;
}
