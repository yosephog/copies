#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"




void remove_last(node_type* first){
  printf("ENTERD REMOVING AND REMOVING \n" );
  node_type* temp=first;
  while(temp->next->next != NULL){
    temp=temp->next;
  }
  printf("removing %d %s\n",temp->id,temp->cmd_list );
  free(temp->next);
  temp->next=NULL;

}


node_type* add_first(node_type** first,int lengde,char* cmd){
  node_type* temp=(struct node*)malloc(sizeof(node_type));

  temp->id=lengde;
  strcpy(temp->cmd_list,cmd);
  temp->next=*first;
  *first=temp;


 return temp;
}

void print(node_type* first){

node_type*  temp=first;
    //printf("%d %s\n",temp->id,temp->cmd_list);
  while(temp != NULL){
    printf("%d %s\n",temp->id,temp->cmd_list);
    temp=temp->next;
  }
}
