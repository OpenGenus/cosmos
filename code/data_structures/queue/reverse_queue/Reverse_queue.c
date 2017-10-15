#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct tag
{
        int a[SIZE];
        int top;
};   //Structure definition for stack
typedef struct tag stack;


struct tagg
{
        int items[SIZE];
        int rear;
        int front;
};  //Structure definition for queue
typedef struct tagg QUEUE;


void push();
int pop();
void display();
void rev(); //Function declarations(parameters not required at declaration)


int main()
{
        int ch, element, dnum;
        stack st;
        st.top= -1;
 
        do
        {       //Displaying menu for operations on stack
                printf("\n1.) PUSH");
                printf("\n2.) POP");
                printf("\n3.) DISPLAY");
                printf("\n4.) REVERSE");
                printf("\n5.) EXIT");
                printf("\nEnter your choice: ");
                scanf("%d", &ch);
  
                switch(ch)
                {
                        case 1: printf("\nEnter element to push: ");
                                    scanf("%d", &element);
                                    push(&st, element);
                                    break;
     
                        case 2: dnum = pop(&st);
                                    if(dnum != -1)
                                    printf("\nDeleted element: %d", dnum);
                                    break;
     
                        case 3: display(st);
                                    break;
     
                        case 4: rev(&st);
                                    break;
   
                        case 5: break;
   
                        default: printf("\nWrong choice!! Enter choice again.");
                  }
         }while(ch!=5);
 
}

void push(stack *s, int ele)
{
        if(s->top == SIZE-1)
        {
                printf("\nStack is overflow");
        }
        else
        {
                (s->top)++;
                s->a[s->top] = ele;;
        }
}

int pop(stack *s)
{
        if(s->top == -1)
        {
                printf("\nStack is underflow");
                return(-1);
        }
        else
        {
                return(s->a[(s->top)--]);
        }
}

void display(stack s)
{
        int i;
        if(s.top == -1)
        {
               printf("\nStack is empty");
        }
        else
        {
                for(i=s.top; i>=0; i--)
                {
                           printf("\n%d", s.a[i]);
                }
          printf("\n");
         }
}

//Function to reverse a stack using queue
void rev(stack *s)
{
        QUEUE q;
        q.rear = -1;
        q.front = 0;
 
        if(s->top==-1)
        {
                printf("\nStack empty");
                return;
        }
 
        while((s->top) > -1)
        {
                 q.items[++(q.rear)] = s->a[(s->top)--];
        }
 
        while(q.front <= q.rear)
        {
                  s->a[++(s->top)] = q.items[(q.front)++];
        }
 
}
