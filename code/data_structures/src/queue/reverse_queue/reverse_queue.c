#include<stdio.h>
#include<stdlib.h>
 
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct queue *q){
    if(q->r==q->f || q->f==-1){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        if(q->f==-1)
        {
            q->f=0;
        }
        q->r++;
        q->arr[q->r] = val;
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        a = q->arr[q->f]; 
        q->f++;
    }
    return a;
}
void reverseQueue(struct queue *q)
{
    // Base case
    if (isEmpty(q))
        return;
 
    // Dequeue current item (from front) 
    long long int data = q->arr[q->f];
    dequeue(q);
 
    // Reverse remaining queue 
    reverseQueue(q);
 
    // Enqueue current item (to rear) 
    enqueue(q,data);
}
void traversal(struct queue *q)
{
    if (q->f==1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("\nQueue is printing...\n");
    int i;
    for ( i = q->f; i <=q->r ; i++)
    {
        printf("%d ",q->arr[i]);
    }
    
    
}
int main(){
    struct queue q;
    struct queue q1;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    
    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1); 
    
    traversal(&q);
    reverseQueue(&q);
    printf("\nAfter reverseing");
    traversal(&q);
    
 
    return 0;
}
