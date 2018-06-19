/* Check weather element is present in link list (iterative method)*/
/* Part of Cosmos by OpenGenus Foundation */

#include <stdio.h>
#include <stdlib.h>
struct node{                                    /* defining a structure named node */
    int data; struct node* next;                          
};

void
insert(struct node **head , int data)           /* insert an integer to the beginning of the list */
{
        struct node* temp = (struct node*)malloc(sizeof(struct node*));
        temp->data = data;
        temp->next = *head;
        *head = temp;

}

void
find(struct node **head , int n)              /* delete the node at nth position */
{
    struct node* temp1 = *head;
    while (temp1 != NULL)
    {
        if (temp1->data == n){
        printf ("Element found\n");
        return;}
        temp1 = temp1->next;
    }
    printf ("Element Not found \n");
    return ;
}

void
result(struct node **head)                  /* print all the elements of the list */
{
    struct node* temp = *head;
    printf ("list:");
    while (temp != NULL){
        printf ("%d " , temp->data);
        temp = temp->next;
    }
    printf ("\n");
}

int
main()
{
    struct node* head = NULL;               /* empty list */
    insert (&head , 2);
    insert (&head , 4);
    insert (&head , 5);
    insert (&head , 7);
    insert (&head , 8);                     /* List:2 4 5 7 8 */
    result (&head);
    int n;
    printf ("Enter the element:");
    scanf ("%d" , &n);
    find (&head , n);
    return (0);
}

