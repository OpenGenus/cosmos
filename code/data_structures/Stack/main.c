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

			int num = POP(&head);

			printf("\n Popped element is = %d\n",num);
			printf("Enter any character to continue\n");
			getchar();
			
			break;
		default :
			return 1;
	}
	}
	
	return 0;
}
	
	
