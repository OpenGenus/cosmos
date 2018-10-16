#include<stdio.h>

int queue[5];
int head=0,tail=0;

void enqueue(int);
void dequeue(int);
void display(int);

int main()
{
     int x;
     int max=5;
     while (1)
     {
         printf("enter i to enqueue\n 2 to dequeue \n 3 to display");
         scanf("%d",&x);
         switch (x) {
         case 1 :
                 enqueue(max);
                 break;
         case 2 :
                 dequeue(max);
                 break;
         case 3 :
                 display(max);
                 break;  
         default:
                 printf("enter valid input");        
         }
     }
     return (0);
}


void enqueue(int max)
{
     int val;
     printf("enter a value");
     scanf("%d",&val);
     if (tail!=head-1 && tail<max-1) {
           queue[tail]=val;
           tail++;
     }
     else if (head!=0 && tail==max-1) {
           queue[tail]=max;
           tail=0;
     }
     else {
           printf("queue is full");
     }
}



void dequeue(int max)
{
      if (tail==0) {
           printf("queue is empty");
      }
      else {
           printf("the element is %d",queue[head]); 
      }
      if (head==max-1) {
           head=0; 
      }
      else {
           head++;
      }
}

void display(int max)
{
      if (tail==0) {
           printf("queue is empty");
      }
      else {
           int i;
           i=head;
           if (head>tail) {
                     for (;i!=max;i++)
                     {
                         printf("%d",queue[i]);
                     }
                     for (i=0;i<tail;i++)
                     {
                         printf("%d",queue[i]);
                     }
           }
           else if (head<tail) {
                     for (i=head;i<tail;i++)
                     {
                         printf("%d",queue[i]);
                     }
           }
      }
}
