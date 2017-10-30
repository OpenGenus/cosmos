#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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


void print_list(node* tmp)
{
  while (tmp)
  {
    printf("%d ", tmp->value);
    tmp = tmp->next;
  }
  printf("\n");
}

void reverse_list()
{
    node* trail_ptr = head;
    node* tmp = trail_ptr->next;
    node* lead_ptr = tmp;
    if (!tmp)
      return;
    while (lead_ptr->next)
    {
	lead_ptr = lead_ptr->next;
        if (lead_ptr)
        {
           tmp->next = trail_ptr;
           if (trail_ptr == head)
             head->next = NULL;
           trail_ptr = tmp;
           tmp = lead_ptr;
        }
     }
     tmp->next = trail_ptr;
     if (trail_ptr == head)
       trail_ptr->next = NULL;
     trail_ptr = tmp;
     if (lead_ptr != tmp)
       lead_ptr->next = tmp;
     if (lead_ptr)
       head = lead_ptr;
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
        int num_nodes, value, ctr;
        printf("Enter number of nodes\n");
        scanf("%d",&num_nodes);
        for (ctr = 0; ctr < num_nodes; ctr++)
        {
           printf("Enter value\n");
           scanf("%d",&value);
           create_list(value);
        }
        print_list(head);
        reverse_list();
        print_list(head);
        cleanup_list();
	return 0;
}           
