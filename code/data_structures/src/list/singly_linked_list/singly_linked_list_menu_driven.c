// use -1 option to exit
// to learn about singly link list visit https://blog.bigoitsolution.com/learn/data-structures/922/

#include <stdio.h>
#include <stdlib.h>
 
struct Node 
{
	int data;
	struct Node* next;
};

int main()
{
	int opt, value, flag, loc;
	struct Node *head, *new_node, *temp;
	head = (struct Node*)malloc(sizeof(struct Node));
	head = NULL;   // initially head is empty
	do
	{
		printf("Insertion : \n");
		printf("1. At beginning\t\t2. In between\t\t3. At end\n");
		printf("Deletion : \n");
		printf("4. From beginning\t5. From between\t\t6. From end\n");
		printf("Other :\n");
		printf("7. Size\t\t\t8. Is Empty\t\t9. Search\n");
		printf("       \t\t\t0. Print\n> ");
		scanf("%d", &opt);
		switch(opt)
		{

			// case to insert node in the begining
			case 1:
				printf("enter any integer ");
				scanf("%d", &value);
				new_node = (struct Node*)malloc(sizeof(struct Node));
				if(new_node == NULL)
				{
					printf("Failed to allocate memory\n");
					return 0;
				}
				new_node->data = value;
				new_node->next = NULL;
				if(head == NULL)
				{
					head = new_node;
				}
				else
				{
					new_node->next = head;
					head = new_node;
				}
				new_node = NULL;
				free(new_node);
			break;

			// case to add node at location
			case 2:
				if(head == NULL)
				{
					printf("List is empty\n");
					break;
				}
				printf("enter an integer ");
				scanf("%d", &value);
				new_node = (struct Node*)malloc(sizeof(struct Node));
				new_node->data = value;
				new_node->next = NULL;
				printf("enter location ");
				scanf("%d", &loc);
				flag = 1;
				loc--;  // because we hve to stop traversing before the location
				temp = (struct Node*)malloc(sizeof(struct Node));
				temp = head;
				while(temp->next!=NULL && flag!=loc)
				{
					temp=temp->next;
					flag++;
				}
				new_node->next = temp->next;
				temp->next = new_node;
				temp = NULL;
				new_node = NULL;
				free(temp);
				free(new_node);
			break;

			// case to add node at last 
			case 3:
				printf("enter an integer ");
				scanf("%d", &value);
				new_node = (struct Node*)malloc(sizeof(struct Node));
				new_node->next = NULL;
				new_node->data = value;
				if(head == NULL)
				{
					head = new_node;
				}
				else
				{
					temp = (struct Node*)malloc(sizeof(struct Node));
					temp = head;
					while(temp->next != NULL)
            			temp = temp->next;
            		temp->next = new_node;
				}
				temp = NULL;
				free(temp);
				new_node = NULL;
				free(new_node);
			break;

			// case to delete node from begining
			case 4:
				if(head == NULL)
				{
					printf("List is empty\n");
				}
				else
				{
					temp = (struct Node*)malloc(sizeof(struct Node));
					temp = head;
					head = head->next;
					printf("%d is deleted\n", temp->data);
					free(temp);
				}
			break;

			// case to delete node from a location
			case 5:
				if(head==NULL)
				{
					printf("List is empty\n");
				}
				else
				{
					printf("enter location ");
					scanf("%d", &loc);
					loc--;
					flag = 1;
					temp = (struct Node*)malloc(sizeof(struct Node));
					new_node = (struct Node*)malloc(sizeof(struct Node));
					temp = head;
					while(temp->next!=NULL && flag!=loc)
					{
						temp=temp->next;
						flag++;
					}
					new_node = temp->next;
					printf("%d is deleted\n", new_node->data);
					temp->next = new_node->next;
					temp = NULL;
					free(new_node);
					free(temp);
				}
			break;

			// case to delete node from last
			case 6:
				if(head==NULL)
				{
					printf("List is empty\n");
				}
				else
				{
					temp = (struct Node*)malloc(sizeof(struct Node));
					new_node = (struct Node*)malloc(sizeof(struct Node));
					temp = head;
					
					while(temp->next->next!=NULL)
					{
						temp=temp->next;
					}
					new_node = temp->next;
					printf("%d is deleted", new_node->data);
					temp->next = NULL;
					free(new_node);
					temp = NULL;
					free(temp);
				}
			break;

			// case to print the size of list
			case 7:
				printf("Size is : ");
				if(head==NULL)
				{
					printf("0\n");
				}
				else
				{
					flag = 0;
					temp = (struct Node*)malloc(sizeof(struct Node));
					temp = head;
					while(temp!=NULL)
					{
						flag++;
						temp=temp->next;
					}
					printf("%d\n", flag);
					free(temp);
				}
			break;
			
			// case to check whether the list is empty or not
			case 8:
				if(head==NULL)
				{
					printf("List is empty\n");
				}
				else
				{
					printf("List is not empty\n");
				}
			break;

			// case to print the location(s) of a node->data
			case 9:
				if(head == NULL)
				{
					printf("List is empty\n");
				}
				else
				{
					flag = 1;
					printf("enter number to search ");
					scanf("%d", &value);
					printf("%d is found at : ", value);
					temp = (struct Node*)malloc(sizeof(struct Node));
					temp = head;
					while(temp!=NULL)
					{
						if(temp->data == value)
							printf("%d ", flag);
						flag++;
						temp = temp->next;
					}
					printf("\n");
					free(temp);
				}
			break;

			// case to print the list
			case 0:
				if(head==NULL)
				{
					printf("List is empty\n");
				}
				else
				{
					temp = (struct Node*)malloc(sizeof(struct Node));
					temp = head;
					while(temp!=NULL)
					{
						printf("%d -> ", temp->data);
						temp = temp->next;
					}
					printf("NULL\n");
					free(temp);
				}
			break;
		}
		printf("\n=====================================\n");
	}while(opt!=-1);
	free(head);
	return 0;
}
