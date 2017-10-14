#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*start=NULL;

void create()
{
    struct node *newnode, *p;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the Data:\n");
    scanf("%d",&newnode->data);
    if(start == NULL)
    {
        start = newnode;
    }
    else
    {
        p=start;
        while(p->next != NULL)
        {
            p=p->next;
        }
        p->next = newnode;
    }
    newnode->next = NULL;
}

void display()
{
    struct node *p;

    if( start==NULL)
    {
        printf("No data\n");
    }
    else
    {
        p=start;
        while(p->next != NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        printf("%d\n",p->data);
    }
}

void reverse(struct node *p)
{
    if(!p)
        return;

    reverse(p->next);
    printf("%d ",p->data);
}

int main()
{
    int size;
    printf("Enter size of linked list\n");
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        create();
    }
    printf("Original list is :\n");
    display();
    printf("\nReversed list is:\n\n");
    reverse(start);
}

