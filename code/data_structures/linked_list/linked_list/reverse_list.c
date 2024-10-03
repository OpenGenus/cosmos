/*
This program is to reverse the linked list using recursive method.
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void choices()
{
	printf("\n\nYou have following choices.\n");
	printf("1: \tTo insert into the list.\n");
	printf("2: \tTo reverse the list.\n");
	printf("3: \tTo print the list.\n");
	printf("-1: \tTo quit.\n\n");
}

struct node *make(int x){
	struct node *p=(struct node *)malloc(sizeof(struct node));
	p->next=NULL;
	p->data=x;
	return p;
}


struct node* reverse (struct node* head) {
  if(head->next == NULL)
    return head;
  else {
    struct node* newhead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
  }
}

struct node *insert(struct node *head,int x)
{
	struct node *temp=head;
	struct node *newnode = make(x);

	if(head==NULL)
	{
		head=newnode;
	}

	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
	return head;
}

void print(struct node *head)
{
	if(head==NULL)
	{
		printf("\n\nEMPTY LIST.\n\n");
	}
	
	else
	{
		printf("\n\nList is.\n");
		while(head!=NULL)
		{
			printf("%d ",head->data);
			head=head->next;
		}
		printf("\n\n");
	}
}

int main(){
	struct node *head;
	head=NULL;
	choices();
	int ch;
	scanf("%d",&ch);
	while(ch!=-1)
	{
		if(ch==1)
		{
			int x;
			printf("Enter the value you want to insert into the list:\t");
			scanf("%d",&x);
			head=insert(head,x);
			printf("Inserted element into into the list. Element value:\t%d",x);
		}
		
		else if(ch==2)
		{
			if(head==NULL) printf("\nEmpty list.\n");
			else
			{
				head=reverse(head);
				printf("\nReversed the list.\n");
			}
		}
		
		else if(ch==3)
		{
			print(head);
		}
		
		else
		{
			printf("\n\nNONE OF THE CHOICES MATHES YOUR INPUT.\n\n");
			choices();
		}
		printf("\n\nEnter your choice: \t");
		scanf("%d",&ch);
	}
		
	return 0;
}
