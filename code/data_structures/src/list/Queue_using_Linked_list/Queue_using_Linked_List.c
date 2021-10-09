#include<stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node * rear=0;
struct node * front=0;

//insertion
void enqueue(int x)
{
    struct node * temp=0;
    temp=(struct node *)malloc(sizeof(struct node));

    if(temp==0)
    {
        printf("\nQueue Overflow");
        return;
    }

    temp->data=x;
    temp->next=0;

    if(front==0 && rear==0)
    {
        front=temp;
        rear=temp;
    }

    else
    {
        rear->next=temp;
        rear=temp;
    }
}

//deletion
void dequeue()
{
    if(front==0 && rear==0)
    {
        printf("\nQueue underflow");
        return;
    }

    struct node * temp=front;
    temp=(struct node *)malloc(sizeof(struct node));

    if(front==rear)
    {
        front=0;
        rear=0;
    }

    else
    {
        front=front->next;
        free(temp);
    }
}

//printing the elements
void print()
{
    if(front==0 && rear==0)
    {
        printf("\nQueue underflow");
        return;
    }

    printf("\nQueue: ");
    struct node *temp = front;
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}


int main()
{
    print();
    enqueue(10);
    print();
    enqueue(20);
    enqueue(30);
    print();
    dequeue();
    dequeue();
    print();
    dequeue();

    return 0;
}
