#include <stdio.h>
#include <stdlib.h>
#define NUM_NODES 100 
// Part of Cosmos by OpenGenus Foundation
typedef struct node {
		int value;
		struct node* next;
	}node;

node* head = NULL;

node* create_node(int val)
{
   node *tmp = (node *) malloc(sizeof(node));
   tmp->value = val;
   tmp->next = NULL;
   return tmp;
}

void create_list(int val)
{
        static node* tmp = NULL;
        if (!head)
        {
           head = create_node(val);
           tmp = head;
        }
        else
        {
           tmp->next = create_node(val);
           tmp = tmp->next;
        }
}

node* ptr = NULL;
void  get_nth_node(int node_num,node* curr)
{
	static int ctr = 0;
        if (curr->next)
        {
          get_nth_node(node_num,curr->next );
        }
        ctr++;
        if (ctr == node_num)
          ptr = curr;
}

void cleanup_list()
{
  node* tmp = NULL;
  while (head->next)
  {
    tmp = head;
    head = head->next;
    free(tmp);
  }
  free(head);
  head = NULL;
}


int main()
{
      int node_num,ctr;
      node* tmp = NULL;
      printf("Enter node number\n");
      scanf("%d",&node_num);
      for (ctr = 0; ctr < NUM_NODES; ctr++)
         create_list(ctr); 
      get_nth_node(node_num, head);
      if ((node_num > 0) && (node_num <= NUM_NODES))
        printf("curr->value = %d\n",ptr->value);
      else
        printf("node number has to be greater than 0\n");
      cleanup_list();
      return 0;
}



	
