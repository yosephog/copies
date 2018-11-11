#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
   char buf[64];
   printf("Enter something \n");
   // dont use gets it is not wise and scanf only for number use fgets
   //gets(buf);

   fgets(buf,sizeof(buf),stdin);
   printf("you enterd %s\n",buf );
    char* name="yoseph";
    for(unsigned int i=0;i<strlen(name);i++){
       if(name[i]=='\0')
         printf("got endline  \n" );
        else
          printf("printing something %c \n",name[i] );
    }
  return 0;
}
