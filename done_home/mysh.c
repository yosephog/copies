#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>


#define MAX_INPUT_LENGTH 120  // the maximum length of input
#define MAX_ANTALL_COMMAND 20 // the maximum number of words or command
#define MAX_SAVED_COMMAND 15  // the maximum amount that can be saved befor starting to delete

//define SIGKILL 1             // 1 to kill a specific

 int last_cmd_index=0;  // the last index of the input commands after parsing
 int command_counter=0; // count the number of commands for mysh.this is displayed with it
 int cmd_id=0; // this keep count how many command are in the history dicrements
              //when commands are deleted
/*
 this struct is used for the job part. the pid to hold the pid
 number and the command to hold the command
*/
struct job{
  int pid;
  char command[MAX_INPUT_LENGTH];
};
struct job* jobs_and_pid[MAX_SAVED_COMMAND]; // to hold all the jobs that are inputed
int job_counter=0;  // counter for the jobs that are inserted

/**
 the linked list to hold the commands
**/
typedef struct node{
  int id;   // the index that is saved in
  int input_length; // length of the commands that are inputed
  struct node* next;
  char cmd_list[MAX_INPUT_LENGTH]; // to save the command
}node_type;

node_type* command_history[15]; // used to hold the commands in the linked list


void read_line(char line[]){

  fgets(line,MAX_INPUT_LENGTH,stdin);

#ifdef DEBUG
  printf("=======ENTERD ARGUMENT==================\n" );
  printf("%s\n",line );
  printf("-----------------------\n" );
#endif

}
/**
this method parse the line that is givien using strtok
**/
int parsed_line(char* line,char* parsed_array[]){

  int index=0;  // to count the number of commands that are parsed.
  parsed_array[index]=strtok(line," \n");

  // checking if it have reached the maximum allowed command
  while(parsed_array[index] != 0 && index < MAX_ANTALL_COMMAND){
    index++;
    parsed_array[index]=strtok(NULL," \n");
  }
  parsed_array[index]=0; // zeroing at finish index
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
 return index;
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
      printf("mysh: %s: command not found\n",parsed_cmd[0] );
      perror("execvp()");
      exit(EXIT_FAILURE);
    }
    int mypid=getpid();
    return mypid;
  }
  else{
    // jobs* temp=malloc(sizeof(struct jobs));

    int status=wait(&status); // waiting for child process and saving child pid
    // saveing the job using the job struct
   struct job* temp=malloc(sizeof(struct job));
      temp->pid=status;
      strcpy(temp->command,parsed_cmd[0]);
      jobs_and_pid[job_counter]=temp;
      job_counter++;

    if(strcmp(parsed_cmd[last_cmd_index],"&") == 0){
      printf("child pid is %d\n",status);
    }
  }
  return 0;
}

void print_jobs(){
  //int i=0;
  int i=cmd_id;
  //int in=0;
   while(i>=0){
     if(jobs_and_pid[i] != 0)
       printf("Pid        = %d \nCommand line = %s \n",jobs_and_pid[i]->pid,jobs_and_pid[i]->command);
     i--;
   }
}

void print_command_history(node_type* cmd[]){
   int i=0;
   printf("==========printing command history=================\n");
   while(i < cmd_id){
     if(cmd[i] != NULL){
     printf("command_history[%d] id--> %d \n",i,cmd[i]->id);
      printf("command_history[%d] length--> %d  \n",i, cmd[i]->input_length);
      printf("command_history[%d] inputs -->%s\n",i, cmd[i]->cmd_list);
      printf("==================================================\n" );

   }
   i++;
   }
}
void print_history(node_type* cmd[]){
   int i=cmd_id;
   int in=0;
   while(in <= i){
      if(cmd[in] != NULL){
     printf("%d: %s \n",in,cmd[in]->cmd_list);

   }

   in++;
   }
}
node_type* add_first(node_type** first,int id,int lengde,char* cmd){
  node_type* temp=(struct node*)malloc(sizeof(node_type));
//  printf("Testing input commands %s \n",cmd );
  temp->id=id;
  temp->input_length=lengde;
  strcpy(temp->cmd_list,cmd);
  temp->next=*first;
  *first=temp;
  command_history[temp->id]=temp;
  /**  printf("INPUTING and saving\n");
    printf("input id -- %d \n input length -- %d \n input is %s\n",temp->id,temp->input_length,temp->cmd_list);

   print_command_history(command_history); **/
 return temp;
}

void print(node_type* first){

  node_type*  temp=first;
    //printf("%d %s\n",temp->id,temp->cmd_list);
  while(temp->next != NULL){
    printf("%d %s\n",temp->id,temp->cmd_list);
    temp=temp->next;
  }
}

node_type* remove_last(node_type* first){
  printf("ENTERD REMOVING AND REMOVING \n" );
  node_type* temp=first;
  while(temp->next->next != NULL){
    temp=temp->next;
  }
  node_type* ret=temp;
  free(temp->next);
  temp->next=NULL;
   printf("%d %d %s\n",ret->id,ret->input_length,ret->cmd_list);
   command_history[ret->id]=0;

  return ret;
}


void print_binary(int num)
{
	int pos = (sizeof(int) * 8) - 1;
	printf("%10d: ", num);

	for (int i = 0; i < (int)(sizeof(int) * 8); i++) {
		char c = num & (1 << pos) ? '1' : '0';
		putchar(c);
		if (!((i + 1) % 8))
			putchar(' ');
		pos--;
	}
	putchar('\n');
}
void print_bitmap_binary(node_type* cmd[]){
    for(int i=0;i<command_counter;i++){
      if(cmd[i] != NULL){
      printf("command id    -- ");
      print_binary(cmd[i]->id);
      printf("command length --");
      print_binary(cmd[i]->input_length);
      printf("inputed argument --\n ");
      char temp_array[cmd[i]->input_length];
      strncpy(temp_array,cmd[i]->cmd_list,cmd[i]->input_length);
      int j=0;
      while(j < cmd[i]->input_length){
        int cast=(int)temp_array[j];
        print_binary(cast);
        j++;
      }
    }
    }
}
int main(void){
  node_type* first=NULL;
  first=malloc(sizeof(node_type));
  char* user = getenv("USER");
  node_type* temp;
  node_type* ret;
  while(1){
    command_counter++;
    printf("%s@mysh %d>",user,command_counter );
    char line[MAX_INPUT_LENGTH];
    char line2[MAX_INPUT_LENGTH];
    char* parsed[MAX_ANTALL_COMMAND+1]; // the plus one for the parm[21]

     read_line(line2);
      strcpy(line,line2);

   int len_cmd=parsed_line(line2,parsed);

     if(strcmp(parsed[0],"quit")==0){
       printf("EXITING MYSHELL\n");
       printf("Goodby\n");
       free(first);
       return 0;
     }

     else if(strcmp(parsed[0],"h")== 0){
         if(len_cmd == 2){
           printf("ENTERD H -I changing %s\n",parsed[1]);
           int index=atoi(parsed[1]);
           printf("printing the index %d\n",index );
           char cmd[120];
           strcpy(cmd,command_history[index]->cmd_list);
           printf("getting value at index %s\n",cmd );
           char* temp_parse[21];
           parsed_line(cmd,temp_parse);
           execute_parsed(temp_parse);
      }
      if(len_cmd == 3 ){
        if(strcmp(parsed[1],"-d")==0){
        int index=atoi(parsed[2]);
        printf("ENTERING TO REMOVE AT %d \n",index );
        command_history[index]=0;
      }
      }
        else{
       printf("History of the last %d command \n",command_counter);
       //print(first);
      // print_command_history(command_history);
       if(cmd_id==MAX_SAVED_COMMAND){
        ret= remove_last(first);
         cmd_id--;
         remove_last(first);
         temp=add_first(&first,cmd_id,strlen(line),line);
         cmd_id++;
        print_history(command_history);
       }
       else{
         temp=add_first(&first,cmd_id,strlen(line),line);
         cmd_id++;
         print_history(command_history);
     }

     }   //counter++;
   }
   else if(strcmp(parsed[0],"jobs")== 0){
      print_jobs();
   }
   else if(strcmp(parsed[0],"kill")==0){
     printf("killing pid number %s \n",parsed[1]);
     int kill_ret=kill(atoi(parsed[1]),SIGKILL);
     if(kill_ret == -1){
       printf("unable to kill process %s\n",parsed[1] );
       perror("kill()");
       //exit(0);
     }
   }
   else{
     if(cmd_id==MAX_SAVED_COMMAND){
       node_type* ret=remove_last(first);
       cmd_id--;

        temp=add_first(&first,ret->id,strlen(line),line);
       cmd_id++;
       execute_parsed(parsed);
       //free(temp);
     }
     else{

       add_first(&first,cmd_id,strlen(line),line);
       cmd_id++;
         execute_parsed(parsed);

     }
     //counter++;
   }
   //command_counter++;
#ifdef DEBUG
 print_bitmap_binary(command_history);
#endif
  }
  free(ret);
  free(temp);
  free(first);
  return 0;
}
