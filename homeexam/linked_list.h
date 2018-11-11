#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
 int id;
 struct node* next;
 char cmd_list[120];
}node_type;

void remove_last(node_type* first);
node_type* add_first(node_type** first,int lengde,char* cmd);
void print(node_type* first);
