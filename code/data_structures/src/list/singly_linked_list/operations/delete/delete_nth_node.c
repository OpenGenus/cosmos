/* delete the nth node from the link list */
/* Part of Cosmos by OpenGenus Foundation */

#include <stdio.h>
#include <stdlib.h>

struct node{                /* defining a structure named node */
    int data;               /* stores data */
    struct node* next;      /* stores the address of the  next node*/
};

struct node* head;          /* Global */

void
insert(int data)            /* inserts the value at the beginning of the list */
{
    struct node* temp = (struct node*)malloc(sizeof(struct node*));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void
Delete(int n)                /* delete the node at nth position */
{
    struct node* temp1 = head;
    if ( n == 1 ){
        head = temp1->next;
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

void
result()                      /* print all the elements of the list */
{
    struct node* temp = head;
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
    head = NULL;                /* empty list */
    insert(2);
    insert(4);
    insert(5);
    insert(7);
    insert(8);                  /* List:2 4 5 7 8 */
    result();
    int n;
    printf("Enter the position:");
    scanf("%d",&n);
    Delete(n);
    result();
    return (0);
}
