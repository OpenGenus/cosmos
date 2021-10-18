#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node * head=0;

//inserting an element
void push(int x)
{
    struct node * temp=0;
    temp=(struct node *)malloc(sizeof(struct node));

    if(temp==0)
    {
        printf("\nOverflow");
        return;
    }

    temp->data=x;
    temp->next=head;
    head=temp;
}

//delete an element
void pop()
{
    if(head==0)
    {
        printf("\nUnderflow");
        return;
    }

    struct node * temp;
    temp=head;
    head=head->next;
    free(temp);
}

//printing the elements
void print()
{
    if(head==0)
    {
        printf("\nUnderflow");
        return;
    }

    struct node *temp = head;
    printf("\n");
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}


int main()
{
    print();
    push(10);
    print();
    push(20);
    push(30);
    print();
    pop();
    pop();
    pop();
    print();
    pop();

    return 0;
}

