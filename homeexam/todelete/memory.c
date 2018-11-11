#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
  int val;
  struct node* next;
}node_t;

void print_node(node_t* head){
  node_t* current=head;

  while(current != NULL){
    printf("%d\n",current->val );
    current=current->next;
  }
}

int main(void){
  int max=64;
 char** map=malloc(sizeof(char *) * max);
map[5]="chmod";
 for(int i=0;i<10;i++){
   if(map[i] == NULL){
     printf("at index %ld\n",sizeof(map[i]) );
   }
   else{
     printf("Not empty %s \n",map[i] );
   }
 }
 return 0;
}
