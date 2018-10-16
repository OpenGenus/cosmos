#include<stdio.h>

int head=0,tail=0;
int queue[2][50];

void enqueue(int);
void dequeue(int);
void display(int);

int main()
{
    int n;
    int max=50; 
    while (1)
    { 
        printf("enter 1 to enqueue\n 2 to dequeue\n 3 to display\n 4 to exit");
        scanf("%d",&n);
        switch (n) {
        case 1 :
                enqueue(max);
                break;
        case 2 :
                dequeue(max);
                break;
        case 3 :
                display();
                break;
        case 4 :
                exit(1);
        default:
                printf("enter valid number");
        }
    } 
    return (0);
}

void enqueue(int max)
{
    int value,priority,x,i,j;
    printf("enter the value and its priority");
    scanf("%d%d",&value,&priority);
    if (tail==max) {
        printf("queue is full");
    }
    else if (tail<max) {
        queue[0][tail]=value;
        queue[1][tail[=priority;
        for (i=tail;i!=0;i--)
        {
              if (queue[1][i]<queue[1][i-1]) {
                       for (j=0;j<2;j++)
                       {
                       x=queue[j][i];
                       queue[j][i]=queue[j][i-1];
                       queue[j][i-1]=x;
                       }
              }
        }
        tail++;
    }
}

void dequeue(int max)
{
    if (tail==0 || head==max) {
        printf("queue is empty");
    }
    else {
        int i;
        printf("the element removed is %d",queue[0][head]);
        head++;
    }
}

void display()
{
    int i;
    if (tail==0) {
        printf("queue is empty");
    }
    else {
        for (i=head;i<tail;i++)
        {
              printf("%d",queue[0][i]);
        }
    }
}


