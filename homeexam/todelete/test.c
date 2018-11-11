#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


#define MAX_INPUT_LENGTH 120
#define MAX_ANTALL_WORD 20
int comman_counter=0;

char** parse_line(char* txt){
  int index=0;
  char** parsed_list=(char**)malloc(sizeof(char*) * MAX_INPUT_LENGTH);
  for(int i=0;i<MAX_INPUT_LENGTH;i++){
    parsed_list[i]=(char*)malloc(sizeof(char*) * MAX_INPUT_LENGTH);
    //memset(parsed_list[i],0,sizeof(char*));
  }

  parsed_list[index] = strtok(txt," ");

while(parsed_list[index]!=NULL && index < MAX_ANTALL_WORD)
{
  index++;
   parsed_list[index] = strtok(NULL," ");

}


return parsed_list;
}
void  parse(char *line, char **argv)
{
     while (*line != '\0') {       /* if not the end of line ....... */
          while (*line == ' ' || *line == '\t' || *line == '\n')
               *line++ = '\0';     /* replace white spaces with 0    */
          *argv++ = line;          /* save the argument position     */
          while (*line != '\0' && *line != ' ' &&
                 *line != '\t' && *line != '\n')
               line++;             /* skip the argument until ...    */
     }
     *argv = '\0';                 /* mark the end of argument list  */

}

void  execute(char **argv)
{
     pid_t  pid;
     int    status;

     if ((pid = fork()) < 0) {     /* fork a child process           */
          printf("*** ERROR: forking child process failed\n");
          exit(1);
     }
     else if (pid == 0) {          /* for the child process:         */
          if (execvp(*argv, argv) < 0) {     /* execute the command  */
               printf("*** ERROR: exec failed\n");
               exit(1);
          }
     }
     else {                                  /* for the parent:      */
          while (wait(&status) != pid)       /* wait for completion  */
               ;
     }
}

int  main(void)
{
     char  line[1024];             /* the input line                 */
     char  *argv[64];              /* the command line argument      */


     while (1) {                   /* repeat until done ....         */
          printf("Shell -> ");     /*   display a prompt             */
           gets(line);              /*   read in the command line     */
          printf("\n");
          //parse(line, argv);       /*   parse the line               */
          char** par=parse_line(line);
          if (strcmp(par[0], "exit") == 0)  /* is it an "exit"?     */
               exit(0);            /*   exit if it is                */
            printf("The first argument %s\n", argv[0]);
        //  execute(argv);           /* otherwise, execute the command */
          execute(par);
     }
     return 0;
}
