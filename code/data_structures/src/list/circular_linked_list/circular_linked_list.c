
#include<stdio.h>
#include<stdlib.h>

void insert_at_end();
void insert_at_front();
void delete_end();
void delete_front();
void display();
struct Node *root=NULL,*tail=NULL;
struct Node
{
    int data;
    struct Node *next;
};
int
main(int argc, char *argv[])
{
    int choice;

    while (1)
    {
        printf("Enter Choice:\n1.Insert at front\n2.Insert at End\n3.Display\n4.Delete from front\n5.Delete from end\n6.Exit\n");
        scanf("%d",&choice);
        switch (choice){
        case 1:
               insert_at_front();
               break;
        case 2:
               insert_at_end();
               break;

        case 3:
               display();
               break;
        case 4:
               delete_front();
               break;
        case 5:
               delete_end();
               break;
        case 6:
               return (0);


        }

    }

}
/*Function for Inserting  node at the end in circular list*/
void
insert_at_end()
{
    int DATA;
    struct Node *temp;
    printf("Enter Data:");
    scanf("%d",&DATA);
    /*create a node*/
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=DATA;
    temp->next=root;
    /*Checking initial condition at insertion*/
    if (root == NULL)
    {
        root=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }


}
/*Function for inserting at the front in circular linked list*/
void
insert_at_front()
{
    struct Node *temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter Data:");
    scanf("%d",&temp->data);

    if(root==NULL)
    {
        /*Initialize root pointer to the first node's address*/
        tail=root=temp;
        temp->next=temp;
    }
    else
    {
        temp->next=root;
        root=temp;

    }

}
/*Function for traversing list*/
void
display()
{
    struct Node *ptr;
    if (root == NULL)
        printf("List is empty\n");
    else
    {
        ptr=root;
        while (ptr != tail)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("%d\n",ptr->data);

    }


}
/*Function for deleting Node from front*/
void
delete_front()
{

    if (root==NULL)
        printf("Sorry,List is already empty\n");
    else
    {
        struct Node *temp;
        if(root->next==root)
        {
            free(root);
            root=NULL;
        }
        else
        {
            temp=root;
            root=root->next;
            tail->next=root;
            free(temp);

        }

    }

}
/*Function for deleting Node from end*/
void
delete_end()
{
    if(root==NULL)
        printf("Sorry,List is already empty\n");
    else
    {
        struct Node *ptr;
        if(root->next==root)
        {
            free(root);
            root=NULL;

        }
        else
        {
            ptr=root;
            while ( ptr->next != tail )
            {
                ptr=ptr->next;
            }
            ptr->next=root;
            free(tail);
            tail=ptr;
        }



    }
}
