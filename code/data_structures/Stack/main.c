#include <stdio.h>
#include "stack.c"

int main()
{
	node *head;

	createEmptyList( &head);

	int choice,val;

	refresh();

	while(1) {
		refresh();

		int num;

		choice = menu();
	
		switch(choice) {
		
		case 1:
			printf("ENter an element to be pushed into the stack:-\n");
			scanf("%d",&val);
		
			PUSH(&head,val);

			break;
		case 2:
			if(is_empty(head)) {
				printf("Stack is empty\n");
				printf("Please retry with other options\n");
				break;	
			}

			num = POP(&head);

			printf("\n Popped element is = %d\n",num);
			printf("Enter any character to continue: ");
			getchar();
			
			break;
		case 3:
			if(is_empty(head)) {
				printf("Stack is empty\n");
				printf("Please retry with other options\n");
				break;	
			}
			num = PEEK(head);
			printf("THe top element is: %d\n",num);
			printf("Enter any character to continue: ");
			getchar();
			break;
		default :
			exit(1);
		}
	}
	
	
}
	
	
