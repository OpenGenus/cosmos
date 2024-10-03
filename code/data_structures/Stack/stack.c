#include "stack.h"

bool is_empty(node * top)
{
	return ((top == NULL)?true: false);
}

int menu() 
{
	int choice;
	printf("        Options Available\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("Enter 1 to PUSH \n");
	printf("Enter 2 to POP \n");
	printf("Enter any other integer to exit the program \n");
	scanf("%d%*c",&choice);
	return choice;
}

void createEmptyList(node ** top) 
{
	*top = NULL;
}

void PUSH(node ** top, int value) 
{
	node *ptr = malloc(sizeof(node));
	ptr->info = value;
	ptr->next = *top;
	*top = ptr;
}

int POP(node ** top)
{
	int temp = (*top)->info;
	node * ptr = * top;
	*top = (*top)->next;
	free(ptr);
	return temp;
}

void refresh() 
{
	write(STDOUT_FILENO, "\x1b[2J", 4);
	write(STDOUT_FILENO, "\x1b[H", 3);
}	

	
