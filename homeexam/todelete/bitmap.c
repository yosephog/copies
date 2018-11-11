#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct node{
  int val;
  struct node* next;
}node_t;

void print_list(node_t** head){
  node_t* current=*head;
  while(current != NULL){
    printf("%d\n",current->val );
    current=current->next;
  }
}
void add_first(node_t ** head, int val) {
    node_t * new_node;
    new_node = malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

void remove_last(node_t** head) {

    //int retval;
    node_t * current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    /* now current points to the second to last item of the list, so let's remove current->next */
  //  retval = current->next->val;
    free(current->next);
    current->next = NULL;


}

int main(void){
 node_t** head=NULL;
 head=malloc(sizeof(node_t));
 add_first(head,1);
 add_first(head,2);
 add_first(head,3);
 print_list(head);
 remove_last(head);
 print_list(head);

  return 0;
}
