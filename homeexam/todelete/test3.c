#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 120  // the maximum length of input
#define MAX_ANTALL_COMMAND 20 // the maximum number of words or command
#define MEMORY_BLOCK 64
char** history=(char**)malloc(sizeof(char*) * 64);

int command_counter=0;    // the counter of the arguments inputed
char* read_line(){
  char* line=(char*)malloc(MAX_INPUT_LENGTH);
  fgets(line,MAX_INPUT_LENGTH-1,stdin);
  return line;
}

char** parsed_line(char* line){
  char** parsed_array=(char**)malloc(sizeof(char*) * MAX_ANTALL_COMMAND);
  parsed_array[MAX_ANTALL_COMMAND]=0;
  int index=0;
  parsed_array[index]=strtok(line," \n");
  while(parsed_array[index] != 0 && index < MAX_ANTALL_COMMAND){
    index++;
    parsed_array[index]=strtok(NULL," \n");
  }
  return parsed_array;
}
int execute_parsed(char** parsed_cmd){
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
  }
  return 0;
}

void print_history(char** list){
  int index=0;
  while(list[index] != NULL){
    printf("%s\n",list[index] );
    index++;
  }
}
int main(void){
#ifdef 1
  char* user = getenv("USER");
  int index=0;
#else

  while(1){
    printf("%s %d >",user,command_counter );

    char* line=read_line();
    char** parsed=parsed_line(line);
    if(strcmp(parsed[0],"exit") == 0){
      printf("EXITING MYSHELL\n");
      return 0;
    }
    else if(strcmp(parsed[0],"h") == 0){
      print_history(history);
    }
    else{
      history[index]=parsed[0];
      index++;
      execute_parsed(parsed);
      command_counter++;
    }
  }
  return 0;
}
