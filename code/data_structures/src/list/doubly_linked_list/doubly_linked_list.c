#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

Struct node{
int z;
struct node *next,*pre;
}*front=NULL;*rear=NULL;*s=NULL;*a=NULL;*b=NULL;

void main(){
  int x;
  while(1)
  {
     printf("enter 1 to insert\n 2 to to delete \n 3 to display \n 4 to to exit\n");
     scanf("%d",&x);
     switch(x)
     {
       case 1 :insert_node();
               break;
       case 2 :delete_node();
               break;
       case 3 :display();
               break;
       case 4 :exit(1);
       default:printf("enter valid input");
     }
  }
}


int insert_node(){
  int x;
  printf("enter 1 to insert at beginning \n 2 to insert at a specified position \n 3 to insert at ending");
  scanf("%d",&x);
  switch(x)
  {
     case 1 :insert_begin();
             break;
     case 2 :insert_position();
             break;
     case 3 :insert_end();
             break();
     default:printf("enter valid input");
  }
  return(0);
}


int insert_begin(){
   int k;
   printf("enter a value to insert");
   scanf("%d",&k);
   s=(struct node *)malloc(sizeof(struct node));
   s->z=k;
   s->pre=NULL;
   s->next=NULL;
   if(front==NULL)
   {
     front=rear=s;
   }
   else
   {
     s->next=front;
     front->pre=s;
     front=s;
   }
   return(0);
}

int insert_end(){
   int k;
   printf("enter the element");
   scanf("%d",&k);
   s=(struct node *)malloc(sizeof(struct node));
   s->z=k;
   s->pre=NULL;
   s->next=NULL;
   if(front==NULL)
   {
     front=rear=s;
   }
   else
   {
    rear->next=s;
    s->pre=rear;
    rear=s;
   }
   return(0);
}

int insert_position(){
 int i,k,l;
 printf("enter position of node and value");
 scanf("%d%d",&l,&k);
 s=(struct node *)malloc(sizeof(struct node));
 s->z=k;
 s->pre=NULL;
 s->next=NULL;
 a=front;
 b=rear;
 for(i=1;i<l-1;i++)
 {
  a=a->next;
 }
 b=a->next;
 a->next=s;
 s->pre=a;
 s->next=b;
 b->pre=s;
 return(0);
}

int delete_node(){
 int x;
 printf("enter 1 to delete at beginning\n 2 to delete at a specified position \n 3 to delete at ending");
 scanf("%d",&x);
 switch(x)
 {
   case 1 :delete_begin();
           break;
   case 2 :delete_position();
           break;
   case 3 :delete_end();
           break;
   default:printf("enter valid input");
 }
 return(0);
}


int delete_begin(){
 if(front==NULL)
 {
  printf("there are no nodes to delete");
 }
 else if(front==rear)
 {
  printf("the element is %d",front->z);
  front=rear=NULL;
 }
 else
 {
  printf("the element is %d",front->z);
  s=front;
  front=s->next;
  s->next=NULL;
  front->pre=NULL;
 }
 return(0);
}

int delete_end(){
 if(front==NULL)
 {
  printf("there are no nodes to delete");
 }
 else if(front==rear)
 {
  printf("the value is %d",front->z);
  front=rear=NULL;
 }
 else
 {
  printf("the value is %d",rear->z);
  rear=rear->pre;
  rear->next=NULL;
 }
 return(0);
}


int delete_pos(){
 int i,l;
 if(front==NULL)
 {
  printf("there are no nodes to delete");
 }
 else if(front==rear)
 { 
  printf("the element is %d",front->z);
 }
 else
 {
  printf("enter position");
  scanf("%d",&l);
  s=a=front;
  b=rear;
  for(i=1;i<l;i++)
  {
   s=s->next;
  }
  for(i=1;i<l-1;i++)
  {
   a=a->next;
  }
  printf("the element is %d",s->z);
  b=s->next;
  a->next=b;
  b->pre=a;
  s->pre=s->next=NULL;
 }
 return(0);
}

int display(){
 if(front==NULL)
 {
  printf("there are no nodes to display");
 }
 else
 {
  s=front;
  while(s->next!=NULL)
   {
    printf("%d",s->z);
    s=s->next;
   }
  printf("%d",s->z);
 }
 return(0);
}

























