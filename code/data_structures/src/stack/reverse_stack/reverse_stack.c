#include <stdio.h>

#define N 100

void reverse(int*, int*, int*, int, int, int, int);
int pop1(int*, int);
int pop2(int*, int);
int pop3(int*, int);
void isEmpty(int);
void push1(int*, int, int, int);
void push2(int*, int, int, int);
void push3(int*, int, int, int);
int display(int*, int);

void reverse(int* stack1, int* stack2, int* stack3, int top1, int top2, int top3, int n)
{	
	int x,y,z;
	if (top2 == 0 && top3 == 0 && top1 == n-1)
	{
		display(stack1, top1);
	}
	else
	{
		x = pop1(stack1, top1);
		push2(stack1, x, n, top2);
		
		y = pop2(stack2, top2);
		push3(stack2, y, n, top1);

		z = pop3(stack3, top3);
		push1(stack3, z, n, top3);

		reverse(stack1, stack2, stack3, top1, top2, top3,  n);
	}
}	

int pop1(int* stack1, int top1)
{
	if (top1 == -1)	//Checks if array is empty or not
	{
		printf("\nStack Underflow\n");
		return -1;
	}
	else
	{
		return stack1[--top1];
	}
}

int pop2(int* stack2, int top2)
{
	if (top2 == -1)
	{
		printf("\nStack Underflow\n");
		return -1;
	}
	else
	{
		return stack2[--top2];
	}
}

int pop3(int* stack3, int top3)
{
	if (top3 == -1)
	{
		printf("\nStack Undeflow\n");
		return -1;
	}
	else
	{
		return stack3[--top3];
	}
}

void push1(int* stack1, int element, int n, int top1)
{
	if (top1 == n - 1)
	{
		printf("\nStack Overflow\n");
	}
	else
	{
		stack1[++top1] = element;
	}
	
}
void push2(int* stack2 ,int element, int n, int top2)
{
	if (top2 == n - 1)
	{
		printf("\nStack Overflow\n");
	}
	else
	{
		stack2[++top2] = element;
	}
}
void push3(int* stack3, int element, int n, int top3)
{
	if (top3 == n-1)
	{
		printf("\nStack Overflow\n");
	}
	else
	{
		stack3[++top3] = element;
	}
}

void isEmpty(int top1)
{
	if (top1 == -1)
	{
		printf("\nTrue\n");
	}
	else
	{
		printf("\nFalse\n");
	}
}
int display(int* stack1, int top1)
{
	int i;
	printf("The reverse of the stack is-\n");
	for (i=top1; i > -1; i--)
	{
		printf("%d\n", stack1[i]);
	}
}
int main()
{
	int stack1[N], stack2[N], stack3[N];
	int i, n;
	
	printf("Enter the size of stack-\n");
	scanf("%d", &n);

	printf("Enter the stack\n");
	for (i=0; i<n; i++)
	{
		scanf("%d", &stack1[i]);
	}
	int top1=n-1, top2=0, top3=0;
	reverse(stack1, stack2, stack3, top1, top2, top3, n);
	return 0;
}
