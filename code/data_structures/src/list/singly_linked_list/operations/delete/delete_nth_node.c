/* delete the nth node from the link list */
/* Part of Cosmos by OpenGenus Foundation */

#include <stdio.h>
#include <stdlib.h>

struct node{                /* defining a structure named node */
    int data;               /* stores data */
    struct node* next;      /* stores the address of the  next node*/
};


void
insert(struct node **head , int data)            /* inserts the value at the beginning of the list */
{
    struct node* temp = (struct node*)malloc(sizeof(struct node*));
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void
Delete(struct node **head , int n , int *c)                /* delete the node at nth position */
{
    if ( n <= *c ){
        struct node* temp1 = *head;
        if ( n == 1 ){
            *head = temp1->next;
            free(temp1);          /* delete temp1 */
            return;
        }
        int i;
        for (i = 0 ; i < n-2 ; i++)temp1 = temp1->next;

            /* temp1 will point to (n-1)th node */

        struct node* temp2 = temp1->next;   /* nth node */
        temp1->next = temp2->next;          /* (n+1)th node */
        free(temp2);                        /* delete temp2 */
    }
    else printf("Position does not exists!\n");
}
/* Counts no. of nodes in linked list */
int getCount(struct node **head)
{
    int count = 0;  /* Initialize count */
    struct node* current = *head;  /* Initialize current */
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void
result(struct node **head)                      /* print all the elements of the list */
{
    struct node* temp = *head;
    printf("list:");
    while ( temp != NULL ){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int
main()
{
    struct node* head = NULL;                /* empty list */
    insert ( &head , 2 );
    insert ( &head , 4 );
    insert ( &head , 5 );
    insert ( &head , 7 );
    insert ( &head , 8 );                  /* List:2 4 5 7 8 */
    result ( &head );
    int n , c;
    c = getCount( &head );
    printf ("Enter the position:");
    scanf ( "%d" , &n );
    Delete ( &head , n , &c );
    result ( &head );
    return (0);
}
