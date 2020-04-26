#include <stdio.h>
#include <stdlib.h>

int heapSize;
 
void heapify(int* arr, int* index, int i)
{ 
    int largest = i, temp; 
    int left = 2 * i + 1, right = 2 * i + 2;  
    
    if(left < heapSize && arr[left] > arr[largest])
    { 
        largest = left; 
    } 
    
    if( right < heapSize && arr[right] > arr[largest] )  
    { 
        largest = right; 
    } 
      
    if(largest != i) 
    { 
        temp = index[largest];
        index[largest] = index[i];
        index[i] = temp;
        
        temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        
        heapify(arr, index, largest); 
    } 
} 
  
int* heapSort(int* arr, int* index, int n) 
{ 
    for(int i = (n - 1) / 2; i >= 0; i--)
    {
        heapify(arr, index, i); 
    }
    
    int temp;
    
    for(int i = n - 1; i > 0; i--)
    {
        temp = index[0];
        index[0] = index[i];
        index[i] = temp;
        
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        
        heapSize--; 
        heapify(arr, index, 0);
    }
    return index;
} 

int main(void) {
    int n, x, y, tip = 0;
	scanf("%d %d %d", &n, &x, &y);
	
	int a[n], b[n], c[n], d[n];
	
	for(int i = 0; i < n; i++)
	{
	    scanf("%d", &a[i]);
	    d[i] = i;
	}
	
	for(int i = 0; i < n; i++)
	{
	    scanf("%d", &b[i]);
	}
	
	for(int i = 0; i < n; i++)
	{
	    c[i] = abs(a[i]-b[i]);
	}
	
	heapSize = n;
	int* ind = heapSort(c, d, n);
	
	for(int k = n - 1; k >= 0; k--)
	{
	    int i = ind[k];
	    
	    if(a[i] > b[i])
	    {
	        if(x > 0)
	        {
	            tip += a[i];
	            x--;
	        }
	        else
	        {
	            tip += b[i];
                y--;
	        }
	    }
	    else
	    {
	        if(y > 0)
	        {
	            tip += b[i];
                y--;
	        }
            else
            {
                tip += a[i];
	            x--;
            }
	    }
	    
	}
	
    printf("%d\n", tip);
    return 0; 
}

