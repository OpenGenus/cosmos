#include<stdio.h>
#include<stdlib.h>
struct stackrecord
  {
  int *array;
  int capacity;
  int tos;
  };

typedef struct stackrecord *stack;
stack createstack(int max)
  {
  stack s;
  s=malloc(sizeof(struct stackrecord));
    if(s==NULL)
      {
        printf("out of space");
      }
  s->array=malloc((sizeof(int))*max);
    if(s->array==NULL)
      {
        printf("out of space");
      }
  s->capacity=max-1;
  s->tos=-1;
  return(s);
  }
  int isemptys(stack s)
  {
    return s->tos==-1;
  }
  int isfulls(stack s)
  {
    return s->tos==s->capacity;
  }
void push(int x,stack s)
  {
    if(isfulls(s))
      printf("Overflow");
    else
    {
      printf("\n %d is pushed",x);
      s->tos++;
      s->array[s->tos]=x;
    }
    }
  int topandpop(stack s)
  {
    if(isemptys(s))
    {
      printf("\n empty stack");
      return;
    }
  else
    {
      printf("\n %d is popped",s->array[s->tos]);
      return s->array[s->tos--];
    }
  }
struct queuerecord
  {
    int *array;
    int front;
    int rear;
    int capacity;
  };
typedef struct queuerecord *queue;
queue createqueue(int max)
  {
  queue q;
  q=malloc(sizeof(struct queuerecord));
    if(q==NULL)
      printf("Error");
  q->array=malloc(sizeof(int)*max);
    if(q->array==NULL)
      printf("Error");
  q->capacity=max-1;
  q->front=-1;
  q->rear=-1;
  return q;
  } 
int isfullq(queue q)
  {
    return (q->rear==q->capacity);
  }
int isemptyq(queue q)
  {
    return (q->front==-1);
  }
void enqueue(queue q,int x)
  {
    if(isfullq(q))
      printf("overflows");
    else
    {
      printf("\n %d is enqueued",x);
      q->rear++;
      q->array[q->rear]=x;
      if(q->front==-1)
      q->front++;
    }
  }
int frontanddelete(queue q)
  {
  int p;
    if(isemptyq(q))
    {
      printf("underflow");
      return;
    }
    else
    {
      p=q->array[q->front];
      printf("\n %d is front and deleted",p);
      q->front++;
      return p;
    }
  }
void display(queue q)
  {
  int i;
    if(isemptyq(q))
    {
      printf("underflow");
      return;
    }
    for(i=q->front;irear;i++)
    printf("%d\t",q->array[i]);
  }
int main()
  {
  int max,ele,i,choice,n=0,y,z;
  queue q;
  stack s;
  printf("\n Enter the maximum elements:");
  scanf("%d",&max);
  q=createqueue(max);
  s=createstack(max);
    while(1)
    {
      printf("\n Menu:1.Insert 2.Display reversed order 3.exit");
      printf("\n Enter the choice:");
      scanf("%d",&choice);
  switch(choice)
  {
    case 1:
      printf("\n Enter the element:");
      scanf("%d",&ele);
      enqueue(q,ele);
      n++;
      break;
    case 2:
      printf("\n Contents of the queue:");
      display(q);
      for(i=0;i< capacity;i++)
      {
      z=frontanddelete(q),s;
      push(z,s);
      }
      q->front=-1;
      q->rear=-1;
      for(i=0;i< capacity;i++)
      {
      y=topandpop(s);
      enqueue(q,y);
      }
      printf("\n Reversed contents are:");
      display(q);
      break;
    case 3:
      exit(0);
    }
  }
}
