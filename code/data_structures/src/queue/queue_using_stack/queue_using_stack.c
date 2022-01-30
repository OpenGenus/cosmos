#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct stack 
{
    int top;
    unsigned capacity;
    int* A;
} stack;

typedef struct queue 
{
    struct stack* S1;
    struct stack* S2;
} queue;

/*STACK*/
stack* 
createStack(unsigned capacity) 
{
    stack* newStack = (stack*)malloc(sizeof(stack));
    newStack->capacity = capacity;
    newStack->top = -1;
    newStack->A = (int*)malloc(capacity*sizeof(int));
    return (newStack);
}

int 
isFull(stack* S)
{
    return (S->top == S->capacity - 1);
}

int 
isEmpty(stack* S)
{
    return (S->top == -1);
}

void 
push(stack* S, int item)
{
    assert(!isFull(S));
    S->A[++S->top] = item;
}

int 
pop(stack* S)
{
    assert(!isEmpty(S));
    return (S->A[S->top--]);
}

void 
deleteStack(stack* S)
{
	free(S->A);
	free(S);
}

/*QUEUE*/
queue* 
createQueue(stack* S1, stack* S2)
{
    queue* newQueue = (queue*)malloc(2*sizeof(stack*));
    newQueue->S1 = S1;
    newQueue->S2 = S2;
    return (newQueue);
}

void 
enqueue(queue* Q, int item)
{
    push(Q->S1, item);
}

int 
dequeue(queue* Q)
{
    if (!isEmpty(Q->S2)) {
        return (pop(Q->S2));
    }
    while (!isEmpty(Q->S1)) {
        push(Q->S2, pop(Q->S1));
    }
    return (pop(Q->S2));
}

void 
deleteQueue(queue* Q)
{
	free(Q->S1);
	free(Q->S2);
	free(Q);
}

/*driver program*/
int 
main()
{
    stack* S1 = createStack(100);
    stack* S2 = createStack(100);
    queue* Q = createQueue(S1, S2);
    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);
    enqueue(Q, 40);
    /*Current appearance of Q : | 10 | 20 | 30 | 40 | */
    printf("%d\n", dequeue(Q));
    printf("%d\n", dequeue(Q));
    printf("%d\n", dequeue(Q));
    /*Current appearance of Q : | 40 |      10, 20, 30 have been dequeued*/
    enqueue(Q, 5);
    enqueue(Q, 8);
    /*Current appearance of Q : | 40 | 5 | 8 | */
    printf("%d\n", dequeue(Q));
    printf("%d\n", dequeue(Q));
    /*Current appearance of Q : | 8 | */
    deleteQueue(Q);
    return 0;
}
