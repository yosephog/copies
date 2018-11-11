#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stringsum(char* s){
   int sum=0;
   for(int i=0;i<strlen(s);i++){
      if(s[i]>=65 && s[i]>=90 && s[i]>=97 && s[i]<=122){
        sum+=i+1;
      }
      else{
        sum=-1;
        break;
      }
   }
   return sum;
}

int distance_between(char* s, char c){
  int distance=0; int counter=0;
  int tall[2];
   for( int i=0;i<strlen(s);i++){
      if(s[i]==c){
        tall[counter]=i;
        counter++;
        if(counter==2){
          distance=1;
          break;
        }
      }
   }
   if(distance==0)
     return -1;
     else
     return tall[1] - tall[0];
}

//char* string_between(char* s, char c){


char** split(char* s){
  char** st=malloc(sizeof(char* ) * strlen(s) +1);

   for(int i=0;i<strlen(s);i++){
     char* se=malloc(strlen(s));
     strcpy(se,&s[i]);
     printf("%s\n",se );
     st[i]=se;
   }
   return st;
}
int main(void){
  char** v=split("hei du der");

  free(v);
  /** oppgave1
   if(argc < 2){
     printf("usage <message> %s\n",argv[0] );
     return 0;
   }
   for(int i=1;i<argc;i++){
     printf("%s ",argv[i] );
    }
    printf("\n");**/
  //  printf("the sum is %d \n",stringsum("abcd!"));
  //printf("the distance between is %d\n",distance_between("makee",'m'));
//  char* st=string_between("makeem",'m');
//  printf("the string is %s\n",st );
//  free(st);
    return 0;
}
