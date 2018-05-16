#include<stdio.h>
#include<stdlib.h>

struct queue{
    int rear, front,  size;
    unsigned capacity;
    int* array;
};

struct queue* createQueue(unsigned capacity)
{
   struct queue* Q=(struct queue*) malloc(sizeof(struct queue));
   Q->capacity=capacity;
   Q->front=Q->size=0;
   Q->rear=-1;
   Q->array=(int *) malloc(sizeof(Q->capacity * sizeof(int)));
   return Q;
}

int isEmpty( struct queue * Q)
{
    if(Q->size) return 0;
    return 1;
}

int isFull(struct queue * Q)
{
    if(Q->size == Q->capacity) return 1;
    return 0;
}

void enqueue(struct queue * Q)
{
    int data;
    printf("Enter data: ");
    scanf("%d",&data);
    if( isFull(Q)) 
        {
            printf("Queue is Full\n");
        }
    else
    {
        Q->rear=(Q->rear+1)% Q->capacity;
        Q->array[Q->rear]=data;        
        Q->size++;
        printf("Added %d to Queue\n",data);
    }
} 
void dequeue(struct queue * Q)
{
    if( isEmpty(Q)) 
        {
            printf("Queue is Empty\n");
        }
    else
    {
       int item =Q->array[Q->front];
       Q->front=(Q->front+1)% Q->capacity;
       Q->size--;
       printf("Removed %d from Queue\n",item);
    }
}
int main(){
    int size,item;
    char ch;
    printf("Enter the size of Queue: ");
    scanf("%d",&size);
    struct queue * Q = createQueue(size);
    if(Q) printf("a queue of size %d has been created please select the methods:\n",size);
    else
    {
         printf("unable to create a queue\n");
         return 0;
    } 
    
    for(;;)
    {
        printf("a:Enqueue\nb:dequeue\nc:Exit\n");
        scanf(" %c",&ch);
        
       switch (ch)
       {
           case 'a': enqueue(Q);
                   break;
           case 'b': dequeue(Q);
                    break;
           case 'c': return 0;
                   break;
           default: printf("Choice other than a,b,c\n");
                    break;  
       }
    }
    return 1;
}
