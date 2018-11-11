#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "linked_list.h"

#define MAX_INPUT_LENGTH 120  // the maximum length of input
#define MAX_ANTALL_COMMAND 20 // the maximum number of words or command
#define MAX_SAVED_COMMAND 15  // the maximum amount that can be saved
int counter=0;  // counter to count the number of saved commands
int command_counter=0;    // the counter of the arguments inputed
int last_cmd_index=0;

/**
 should return zero when there is no more line to read_line
  uses cltr+d to end the reading of files.
**/
void read_line(char line[]){

  fgets(line,MAX_INPUT_LENGTH,stdin);
#ifdef DEBUG
  printf("=======ENTERD ARGUMENT==================\n" );
  printf("%s\n",line );
  printf("-----------------------\n" );
#endif

}

void parsed_line(char* line,char* parsed_array[]){

  int index=0;
  parsed_array[index]=strtok(line," \n");
  while(parsed_array[index] != 0 && index < MAX_ANTALL_COMMAND){
    index++;
    parsed_array[index]=strtok(NULL," \n");
  }
  parsed_array[index]=0;
  last_cmd_index=index-1;
#ifdef DEBUG
  printf("======PARSED PARAMETERS ================\n");
  int i=0;
  while(parsed_array[i] != NULL ){
    printf("parm[%d]= %s\n",i,parsed_array[i] );
    i++;
  }
  printf("--------------------------------------------\n" );
#endif
}
int execute_parsed(char* parsed_cmd[]){
  pid_t myfork=fork();
  if(myfork == -1){
    perror("fork()");
    exit(EXIT_FAILURE);
  }
  if(myfork == 0){
  //  int excute=execvp(parsed[0],parsed);
    if(execvp(parsed_cmd[0],parsed_cmd) == -1){

      perror("execvp()");
      exit(EXIT_FAILURE);
    }
    return 42;
  }
  else{

    int status;
    wait(&status);
    if(strcmp(parsed_cmd[last_cmd_index],"&") == 0){
      printf("child pid is %d\n",getpid());
    }
  }
  return 0;
}


int main(void){
 node_type* nodes=NULL;
 nodes=malloc(sizeof(node_type));
 //node_type* first;
  
  char* user = getenv("USER");
  while(1){

    printf("%s@mysh %d >",user,command_counter );
    char* parsed[21];
    char line[120];
    read_line(line);
    parsed_line(line,parsed);

    if(strcmp(parsed[0],"quit") == 0){
      printf("EXITING MYSHELL\n");
      free(nodes);
      return 0;
    }
    else if(strcmp(parsed[0],"h") == 0){
      printf("History of the last %d command \n",counter);
      print(nodes);
      if(counter==MAX_SAVED_COMMAND){
        remove_last(nodes);
        counter--;
      }
      command_counter++;
      add_first(&nodes,command_counter,parsed[0]);

      counter++;
    }
    else{
      if(counter==MAX_SAVED_COMMAND){
        remove_last(nodes);
        counter--;
      }
      command_counter++;
      add_first(&nodes,command_counter,parsed[0]);
      execute_parsed(parsed);

      counter++;
}

  }
//  free(first);
 free(nodes);

  return 0;
}
