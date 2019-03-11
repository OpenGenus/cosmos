#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

typedef struct Queue
{
	Node *start, *end;
} Queue;

/*Creates a linked list node.*/
Node
*create_node(int d)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = d;
	temp->next = NULL;
	return (temp);
}

/*Creates an empty queue*/
Queue
*create_queue()
{
	Queue *new_queue = (Queue*)malloc(sizeof(Queue));
	new_queue->start = NULL;
	new_queue->end = NULL;
	return (new_queue);
}

/*Adds a new node to with value x
*to the start of the queue.
*/
void
enqueue(Queue *q, int x)	
{
	Node *new_node = create_node(x);
	if (q->end == NULL)
	{
		q->start = new_node;
		q->end = new_node;
		return;
	}
	q->end->next = new_node;
	q->end = new_node;
}

/*Removes first node in the queue*/
Node
*dequeue(Queue *q)
{
	if (q->end == NULL)
		return NULL;
	Node *temp = q->start;
	q->start = q->start->next;
	if (q->start == NULL)
		q->end = NULL;
	return (temp);
}

/*Prints values of nodes stored in 
* Queue q.
*/
void
print_queue(Queue *q)	
{
	Node *temp = q->start;
	while (temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int
main()
{
	Queue *q = create_queue();
	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 4);
	print_queue(q);
	Node *n=dequeue(q);
	print_queue(q);
	free(q);
	return (0);
}

