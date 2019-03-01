#include<stdio.h>
#include<stdlib.h>

struct stack 
{
    int top;
    unsigned capacity;
    int* A;
};

struct queue
{
    struct stack* S1;
    struct stack* S2;
};

//STACK
struct stack* createStack(unsigned capacity) 
{
    struct stack* newStack = (struct stack*)malloc(sizeof(struct stack));
    newStack->capacity = capacity;
    newStack->top = -1;
    newStack->A = (int*)malloc(capacity*sizeof(int));
    return newStack;
}

int isFull(struct stack* S)
{
    return (S->top == S->capacity - 1);
}

int isEmpty(struct stack* S)
{
    return (S->top == -1);
}

void push(struct stack* S, int item)
{
    if (!isFull(S))
    {
        S->A[++S->top] = item;
    }
    return;
}

int pop(struct stack* S)
{
    if (!isEmpty(S))
    {
        return (S->A[S->top--]);
    }
}

//QUEUE
struct queue* createQueue(struct stack* S1, struct stack* S2)
{
    struct queue* newQueue = (struct queue*)malloc(2*sizeof(struct stack*));
    newQueue->S1 = S1;
    newQueue->S2 = S2;
    return newQueue;
}

void enqueue(struct queue* Q, int item)
{
    push(Q->S1, item);
}

int dequeue(struct queue* Q)
{
    if (!isEmpty(Q->S2))
    {
        return pop(Q->S2);
    }
    else         //if S2 is empty
    {
        while (!isEmpty(Q->S1))
        {
            push(Q->S2, pop(Q->S1));
        }
        return pop(Q->S2);
    }
}



//driver program
int main()
{
    struct stack* S1 = createStack(100);
    struct stack* S2 = createStack(100);
    struct queue* Q = createQueue(S1, S2);
    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);
    enqueue(Q, 40);
    //Current appearance of Q : | 10 | 20 | 30 | 40 |
    printf("%d\n", dequeue(Q));
    printf("%d\n", dequeue(Q));
    printf("%d\n", dequeue(Q));
    //Current appearance of Q : | 40 |      10, 20, 30 have been dequeued
    enqueue(Q, 5);
    enqueue(Q, 8);
    //Current appearance of Q : | 40 | 5 | 8 |
    printf("%d\n", dequeue(Q));
    printf("%d\n", dequeue(Q));
    //Current appearance of Q : | 8 |
    return 0;
}
