// C program to reverse a stack using recursion
// Part of Cosmos by OpenGenus Foundation

#include<stdio.h>
#include<stdlib.h>
#define bool int
 
/* structure of a stack node */
struct sNode
{
    char data;
    struct sNode *next;
};
 
/* Function Prototypes */
void push(struct sNode** top_ref, int new_data);
int pop(struct sNode** top_ref);
bool isEmpty(struct sNode* top);
void print(struct sNode* top);
void insertAtBottom(struct sNode** top_ref, int item);
void reverse(struct sNode** top_ref);
/* Driver program to test above functions */
int main()
{
    struct sNode *s = NULL;
    push(&s, 4);
    push(&s, 3);
    push(&s, 2);
    push(&s, 1);
 
    printf("\n Original Stack ");
    print(s);
    reverse(&s);
    printf("\n Reversed Stack ");
    print(s);
    return 0;
}

// Below is a recursive function that inserts an element
// at the bottom of a stack.
void insertAtBottom(struct sNode** top_ref, int item)
{
    if (isEmpty(*top_ref))
        push(top_ref, item);
    else
    {
 
        /* Hold all items in Function Call Stack until we
           reach end of the stack. When the stack becomes
           empty, the isEmpty(*top_ref)becomes true, the
           above if part is executed and the item is inserted
           at the bottom */
        int temp = pop(top_ref);
        insertAtBottom(top_ref, item);
 
        /* Once the item is inserted at the bottom, push all
           the items held in Function Call Stack */
        push(top_ref, temp);
    }
}
 
// Below is the function that reverses the given stack using
// insertAtBottom()
void reverse(struct sNode** top_ref)
{
    if (!isEmpty(*top_ref))
    {
        /* Hold all items in Function Call Stack until we
           reach end of the stack */
        int temp = pop(top_ref);
        reverse(top_ref);
 
        /* Insert all the items (held in Function Call Stack)
           one by one from the bottom to top. Every item is
           inserted at the bottom */
        insertAtBottom(top_ref, temp);
    }
}

 
/* Driveer program to test above functions */
int main()
{
    struct sNode *s = NULL;
    push(&s, 4);
    push(&s, 3);
    push(&s, 2);
    push(&s, 1);
 
    printf("\n Original Stack ");
    print(s);
    reverse(&s);
    printf("\n Reversed Stack ");
    print(s);
    return 0;
}

 
/* Function to check if the stack is empty */
bool isEmpty(struct sNode* top)
{
    return (top == NULL)? 1 : 0;
}
 
/* Function to push an item to stack*/
void push(struct sNode** top_ref, int new_data)
{
    /* allocate node */
    struct sNode* new_node =
        (struct sNode*) malloc(sizeof(struct sNode));
 
    if (new_node == NULL)
    {
        printf("Stack overflow \n");
        exit(0);
    }
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*top_ref);
 
    /* move the head to point to the new node */
    (*top_ref)    = new_node;
}
 
/* Function to pop an item from stack*/
int pop(struct sNode** top_ref)
{
    char res;
    struct sNode *top;
 
    /*If stack is empty then error */
    if (*top_ref == NULL)
    {
        printf("Stack overflow \n");
        exit(0);
    }
    else
    {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    }
}
 
/* Functrion to pront a linked list */
void print(struct sNode* top)
{
    printf("\n");
    while (top != NULL)
    {
        printf(" %d ", top->data);
        top =  top->next;
    }
}
