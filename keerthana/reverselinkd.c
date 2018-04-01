#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void printReverse(struct Node* head)
{

    if (head == NULL)
       return;

    printReverse(head->next);

    printf("%d  ", head->data);
}

void push(struct Node** head_ref, char new_data)
{
    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));

    new_node->data  = new_data;

    new_node->next = *head_ref;

    *head_ref  = new_node;
}

int main()
{
    //linked list 1->2->3->4
    struct Node* head = NULL;
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printReverse(head);
    return 0;
}
