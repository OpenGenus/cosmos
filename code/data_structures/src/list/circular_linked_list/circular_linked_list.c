#include<stdio.h>
#include<stdlib.h>
typedef struct Node node;
void display(node *tail);
node *insert_at_end(node *tail);
node *insert_at_front(node *tail);
node *delete_at_begin(node *tail);
node *delete_at_end(node *tail);

struct Node{
    int Data;
    struct Node *next;
};
/*Traversing circular linked list*/
void
display(node *tail)
{
    node *root,*ptr;
    if (tail == NULL)
        printf("\nList is empty\n\n");
    else{
        root=tail->next;
        ptr=root;
        while (ptr != tail) {
            printf("%d ",ptr->Data);
            ptr=ptr->next;
        }
        printf("%d\n",ptr->Data);
    }
}
/*Inserting node at front of the list*/
node
*insert_at_front(node *tail)
{       /*Creating new node*/
        node *temp=(node*)malloc(sizeof(node));
        printf("\nEnter Data:");
        scanf("%d",&temp->Data);
        /*Check initial condition for list ,it is empty or not*/
        if (tail == NULL) {
            tail=temp;
            tail->next=temp;
        }
        else {
            temp->next=tail->next;
            tail->next=temp;
        }
        return (tail);
}
/*Inserting node at the end of list*/
node
*insert_at_end(node *tail)
{
    node *temp=(node*)malloc(sizeof(node));
    printf("\nEnter Data:");
    scanf("%d",&temp->Data);
    if (tail == NULL) {
        tail=temp;
        tail->next=temp;
    }
    else {
        node *root;
        root=tail->next;
        tail->next=temp;
        temp->next=root;
        tail=temp;
    }
    return (tail);
}
/*Deleting node at the front of list*/
node
*delete_at_begin(node *tail)
{
    if (tail == NULL)
        printf("\nList is Empty\n\n");
    else {
        if (tail->next == tail) {
            free(tail);
            tail=NULL;
        }
        else {
             node *root,*ptr;
             ptr=root=tail->next;
             root=root->next;
             tail->next=root;
             free(ptr);
        }
    }
    return (tail);
}
/*Deleting node at the end of list*/
node
*delete_at_end(node *tail)
{
    if (tail==NULL)
        printf("\nList is empty\n\n");
    else {
        if (tail->next == tail) {
            free(tail);
            tail=NULL;
        }
        else {
            node *root;
            root=tail->next;
            while (root->next != tail){
                root=root->next;
            }
            root->next=tail->next;
            free(tail);
            tail=root;
        }
    }
    return (tail);
}

int main(int argc, char *argv[])
{   /*Declaring tail pointer to maintain last node address*/
    node *tail=NULL;
    int choice;
    while(1)
    {   /*We can also write print function outside of while loop */
        printf("1.Insert at front\n2.Insert at end \n3.Display\n4.Delete from front\n5.Delete from End\n6.Exit\nEnter choice:");
        scanf("%d",&choice);
        switch(choice)
         {
            case 1:
                    tail = insert_at_front(tail);
                    break;
            case 2:
                   tail = insert_at_end(tail);
                   break;
            case 3:
                    display(tail);
                    break;
            case 4:
                    tail = delete_at_begin(tail);
                    break;
            case 5:
                   tail = delete_at_end(tail);
                   break;
            case 6:
                   return (0);
         }
    }
}
