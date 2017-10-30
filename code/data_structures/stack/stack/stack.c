#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};
 
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}
 
int isFull(struct Stack* stack)
{   return stack->top == stack->capacity - 1; }
 
int isEmpty(struct Stack* stack)
{   return stack->top == -1;  }
 
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}
 

int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
//this function will return the peak of the stack
int peek() {
   return stack[top];
}
//to rverse the stack
void stack_reverse(struct node **head, struct node **head_next)
{
    struct node *temp;
 
    if (*head_next != NULL)
    {
         temp = (*head_next)->next;
        (*head_next)->next = (*head);
        *head = *head_next;
        *head_next = temp;
        stack_reverse(head, head_next);
    }
}
//to reverse the stack without recursion
void stack_reverse(struct node **head)
{
    struct node *temp, *prev;
 
    if (*head == NULL)
    {
        printf("Stack does not exist\n");
    }
    else if ((*head)->next == NULL)
    {
        printf("Single node stack reversal brings no difference\n");
    }
    else if ((*head)->next->next == NULL)
    {
        (*head)->next->next = *head;
        *head = (*head)->next;
        (*head)->next->next = NULL;
    }
    else
    {
        prev = *head;
        temp = (*head)->next;
        *head = (*head)->next->next;
        prev->next = NULL;
        while ((*head)->next != NULL)
        {
            temp->next = prev;
            prev = temp;
            temp = *head;
            *head = (*head)->next;
        }
        temp->next = prev;
        (*head)->next = temp;
    }
}
//to destroy an element in stack
void destroy()
{
    top1 = top;
 
    while (top1 != NULL)
    {
        top1 = top->ptr;
        free(top);
        top = top1;
        top1 = top1->ptr;
    }
    free(top1);
    top = NULL;
 
    printf("\n All stack elements destroyed");
    count = 0;
}
 
int main()
{
    struct Stack* stack = createStack(100);
 
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
 
    printf("%d popped from stack\n", pop(stack));
 
    return 0;
}