#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void updateTreeNodeRange(int* tree, int* lazy, int index, int left, int right, int start, int end)
{
    int l, r, mid;
	
    if(*(lazy + index) == 1)
    {
        *(tree + index) = (right - left +1) - *(tree + index);
          
        if(left != right)
        {
		    l = 2 * index + 1;
		    r = 2 * index + 2;
		   
		    *(lazy + l) ^= 1;
		    *(lazy + r) ^= 1;
        }
        *(lazy + index) = 0;
    }
     
    if ((left > right) || (left > end) || (right < start))
        return; 
          
    if ((left >= start) && (right <= end)) 
    {
        *(tree + index) = (right - left + 1) - *(tree + index);
	    if(left != right)
        {
		    l = 2 * index + 1;
		    r = 2 * index + 2;
		   
		    *(lazy + l) ^= 1;
		    *(lazy + r) ^= 1;
        }
	    return; 
    }

    mid = (left + right) / 2; 
    updateTreeNodeRange(tree, lazy, index * 2 + 1, left, mid, start, end); 
    updateTreeNodeRange(tree, lazy, index * 2 + 2, mid + 1, right, start, end);

    l = 2 * index + 1;
    r = 2 * index + 2;
     
    *(tree + index) = *(tree + l) + *(tree + r);
}

int queryRange(int* tree, int* lazy, int left, int right, int start, int end, int index)
{
    int l, r, mid;
     
	if( *(lazy + index) == 1)
    {
        *(tree + index) = (right - left +1) - *(tree + index);
          
        if(left != right)
        {
		    l = 2 * index + 1;
		    r = 2 * index + 2;
		   
		    *(lazy + l) ^= 1;
		    *(lazy + r) ^= 1;
        }
        *(lazy + index) = 0;
     }

	if ((left > right) || (left > end) || (right < start))  
		return 0; 

	if ((left >= start) && (right <= end)) 
		return *(tree + index); 

	mid = (left + right) / 2;
	
	return (queryRange(tree, lazy, left, mid, start, end, 2 * index + 1) +
		queryRange(tree, lazy, mid + 1, right, start, end, 2 * index + 2)); 
}

int main(void) {
	int n, q;
	
	scanf("%d", &n);
	scanf("%d", &q);
	
	int x = ceil(log(n)/log(2));
	int size = 2*pow(2, x) - 1;
	
	int* tree = (int*)calloc(sizeof(int), (size));
	int* lazy = (int*)calloc(sizeof(int), (size));
	
	while (q>0)
	{
	    q--;
	    int flag, start, end;
	     
	    scanf("%d", &flag);
	    scanf("%d", &start);
	    scanf("%d", &end);
	     
	    if(flag==0)
	    {
	        updateTreeNodeRange(tree, lazy, 0, 0, n-1, start, end);
	    }
        else
        {
            printf("%d\n",queryRange(tree, lazy, 0, n-1, start, end, 0));
        }
	}
	return 0;
}

