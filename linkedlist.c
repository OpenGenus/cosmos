#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{	/*Node in a linked linked list with integer data 
	*and pointer to next node.
	*/
	int data;
	struct Node* next;
}Node;

Node* 
create_node(int data)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	return (temp);
}
void 
print_list(Node* head)
{	/*Prints all the elements of the linked list.*/
	while (head != NULL){
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}
void 
insert_at_beginning(Node** head,int d)
{		/*Inserts new node at the beginning.*/
	Node* temp = create_node(d);
	temp->next = (*head);
	(*head) = temp;
}
void 
insert_after_given_node(Node* node, int node_data)	/*Inserts new node 
							*after the given node.
							*/
{
	if (node == NULL) 
		return;
	else {
		Node* temp = create_node(node_data);
		temp->next = node->next;
		node->next = temp;
	}
}
void 
insert_at_end(Node** head,int d)
{		/*Inserts new node at the end.*/
	Node* temp = create_node(d);
	Node *curr = *head;
	if (*head == NULL) {
		*head = temp;
		return;
	}
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = temp;
}
void 
delete_node(Node* head,int p)
{	/*Deletes node at position p.*/
	Node* temp = head;
	if (p == 0) {
		*head = *head->next;
	}
	else {
		for (int i = 0;i < p-1;i++) {
			temp = temp->next;
		}
		temp->next = temp->next->next;
	}
}
int main(){
	Node* head=create_node(3);
	insert_at_beginning(&head,1);
	print_list(head);
	insert_after_given_node(head,2);
	print_list(head);
	insert_at_end(&head,4);
	print_list(head);
	delete_node(head,3);
	print_list(head);
	return (0);
}
