// C/C++ program to find union and intersection of two unsorted 
// linked lists
// Part of Cosmos by OpenGenus Foundation
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};
 
/* A utility function to insert a node at the beginning of 
   a linked list*/
void push(struct Node** head_ref, int new_data);
 
/* A utility function to check if given data is present in a list */
bool isPresent(struct Node *head, int data);
 
/* Function to get union of two linked lists head1 and head2 */
struct Node *getUnion(struct Node *head1, struct Node *head2)
{
    struct Node *result = NULL;
    struct Node *t1 = head1, *t2 = head2;
 
    // Insert all elements of list1 to the result list
    while (t1 != NULL)
    {
        push(&result, t1->data);
        t1 = t1->next;
    }
 
    // Insert those elements of list2 which are not
    // present in result list
    while (t2 != NULL)
    {
        if (!isPresent(result, t2->data))
            push(&result, t2->data);
        t2 = t2->next;
    }
 
    return result;
}
 
/* Function to get intersection of two linked lists
  head1 and head2 */
struct Node *getIntersection(struct Node *head1, 
                              struct Node *head2)
{
    struct Node *result = NULL;
    struct Node *t1 = head1;
 
    // Traverse list1 and search each element of it in
    // list2. If the element is present in list 2, then
    // insert the element to result
    while (t1 != NULL)
    {
        if (isPresent(head2, t1->data))
            push (&result, t1->data);
        t1 = t1->next;
    }
 
    return result;
}
 
/* A utility function to insert a node at the begining of a linked list*/
void push (struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* A utility function to print a linked list*/
void printList (struct Node *node)
{
    while (node != NULL)
    {
        printf ("%d ", node->data);
        node = node->next;
    }
}
 
/* A utility function that returns true if data is 
   present in linked list else return false */
bool isPresent (struct Node *head, int data)
{
    struct Node *t = head;
    while (t != NULL)
    {
        if (t->data == data)
            return 1;
        t = t->next;
    }
    return 0;
}
 
/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;


    struct Node* intersecn = NULL;
    struct Node* unin = NULL;

    /*create a linked lits 10->15->5->20 */
    push (&head1, 20);
    push (&head1, 4);
    push (&head1, 15);
    push (&head1, 10);

    /*create a linked lits 8->4->2->10 */
    push (&head2, 10);
    push (&head2, 2);
    push (&head2, 4);
    push (&head2, 8);

    intersecn = getIntersection (head1, head2);
    unin = getUnion (head1, head2);

    printf ("\nFirst list is \n");
    printList (head1);

    printf ("\nSecond list is \n");
    printList (head2);

    printf ("\nIntersection list is \n");
    printList (intersecn);

    printf ("\nUnion list is \n");
    printList (unin);
    getch();
    return 0;
}
