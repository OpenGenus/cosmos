/* Part of Cosmos by OpenGenus Foundation */

#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

struct stack
{
    int top;
    int arr[SIZE];
} s;

int 
is_empty()
{
    if(s.top==-1)
        return (1);
    return (0);
}

void 
push(int v)
{
    if(s.top == SIZE - 1)
    {
        printf("stack overflow\n");
        return;
    }
    else
    {
        s.top+=1;
        s.arr[s.top]=v;
    }
}

int 
pop()
{
    if(is_empty())
    {
        printf("stack underflow\n");
        return (-1);
    }
    else
    {
        int q = s.arr[s.top];
        s.top -= 1;
        return (q);
    }
}

int 
safe(int r, int c)
{
	int sum = r+c;
	int diff = r-c;

	for(int i=s.top;i>=0;i--)
	{
		if(sum == i + s.arr[i] || diff == i - s.arr[i] || r == i 
		|| c == s.arr[i])
		{
			return (0);
		}
	}

	return (1);
}

void 
display(int n)
{
	int *a[n];
	for(int i=0; i<n; i++)
	{
        a[i] = (int *)calloc(n,sizeof(int));
	}

	for(int i=s.top;i>=0;i--)
	{
		a[i][s.arr[i]] = 1;
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j])
				printf("Q\t");
			else
				printf("_\t");
		}
		printf("\n");
	}

	printf("\n\n");
}

void 
sol()
{
    int currRow = 0, currCol = 0;
    int flag = 0, n, counter = 0;
    scanf("%d",&n);
    while(1)
    {
    	for(int i = currCol; i < n; i++)
    	{
    		if(safe(currRow, i))
    		{
				currCol = i;
				flag=1;
				break;
    		}
    	}

    	if(flag)
    	{
		 	push(currCol);
		 	currRow += 1;
		 	currCol = 0;
    	}
    	else
    	{
    		if(is_empty())
    		{
    		    if(!counter)
                    printf("No soln\n");
		    	break;
    		}
    		else
			{
		    	currRow -= 1;
    		    currCol = pop() + 1;
			}
    	}


    	if(s.top == n-1)
    	{
    		printf("Solution No. : %d\n", ++counter);
    		display(n);
    		currCol++;
    	}
    	flag = 0;
    }
}


int main()
{
	s.top = -1;
	sol();
	return (0);
}

