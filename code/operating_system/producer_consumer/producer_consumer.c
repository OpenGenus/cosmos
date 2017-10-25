/* Implementation of Producer Consumer Problem by using semaphores in C */

#include<stdio.h>
#include<stdlib.h>
int x=0,a;
int empty=4;
int full=0;
int mutex=1;

//Wait and Signal functions using semaphores
int wait(int s)
{
s--;
return(s);
}
int signal (int s)
{
s++;
return(s);
}
//Code for producer
void produce ()
{
mutex=wait(mutex);
empty=wait(empty);
full=signal(full);
mutex=signal(mutex);
x++;
printf("Produced:%d",x);
}
//Code for Consumer
void consume()
{
mutex=wait(mutex);
full=wait(full);
empty=signal(empty);
mutex=signal(mutex);
printf("Consumed:%d",x);
x--;}

void main()
{
do{
printf("\n 1.producer     2.consumer    3.exit\n enter your choice:");
scanf("%d",&a);
switch(a)
{
case 1:
  if(mutex==1 && empty!=0)
     produce();
 else
     printf("buffer full\n");
 break;
 case 2:
  if(mutex==1 && full!=0)
     consume();
 else
  printf("buffer empty\n");
 break;
  
 case 3:
    exit(0);
    break;
  }
  }while(1);
 }
 
 
