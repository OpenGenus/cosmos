#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
 
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};
 
struct Stack* 
create_stack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return (stack);
}

void 
delete_stack(struct Stack * stack)
{   
    /* completely deletes stack */
    free(stack->array);
    free(stack);
}
 
int 
is_full(struct Stack* stack)
{   
    /* checks for overflow error */
    return (stack->top == stack->capacity - 1); 
}
 
int 
is_empty(struct Stack* stack)
{   
    /* checks for underflow error */
    return (stack->top == -1);  
}
 
void 
push(struct Stack* stack, int item)
{
    assert(!is_full(stack));
    stack->array[++stack->top] = item;
}

int 
pop(struct Stack* stack)
{   
    assert(!is_empty(stack));
    return (stack->array[stack->top--]);
}

int 
main()
{
    struct Stack* stack = create_stack(100);
 
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
 
    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));

    delete_stack(stack);
    
    return (0);
}
