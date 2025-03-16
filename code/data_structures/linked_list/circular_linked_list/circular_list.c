#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *make(int d)
{
	struct node *p=(struct node *)malloc(sizeof(struct node));
	p->data=d;
	p->next=NULL;
	return p;
}
int main()
{
	printf("Enter the no to be inserted into the list. -1 to exit.\n");
	struct node *head;
	head=NULL;
	int d;
	scanf("%d",&d);
	while(d!=-1)
	{
		struct node *p=make(d);
		if(head==NULL)
		{
			head=p;
			p->next=head;
		}

		else
		{
			struct node *temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			temp->next=p;
			p->next=head;
		}

		scanf("%d",&d);
	}

	printf("List is:.\n\n");
	struct node *t=head;
	while(t->next!=head)
	{
		printf("%d ",t->data);
		t=t->next;
	}
	printf("%d\n",t->data);

}
