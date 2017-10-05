// C program for Fibonacci Search
#include <stdio.h>
int min(int x, int y) { return (x<=y)? x : y; }
 
int fibMonaccianSearch(int arr[], int x, int n)
{
    int fibMMm2 = 0;   
    int fibMMm1 = 1;  
    int fibM = fibMMm2 + fibMMm1;  
 
    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM  = fibMMm2 + fibMMm1;
    }
 
    int offset = -1;
 
    while (fibM > 1)
    {
        int i = min(offset+fibMMm2, n-1);
        if (arr[i] < x)
        {
            fibM  = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (arr[i] > x)
        {
            fibM  = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
 

        else
            return i;
    }
    if(fibMMm1 && arr[offset+1]==x)
       return offset+1;
 
    return -1;
}
 
/* driver function */
int main(void)
{
    int n;
    printf("Enter size of array\n");
    scanf("%d",&n);
    int arr[n],i;
    printf("Enter elements of array\n");
    for(i=0;i<n;i++)
    {
         scanf("%d",&arr[i]);
    }
    int x;
    printf("Enter no. to be searched\n");
    scanf("%d",&x);
    printf("Found at index: %d\n",fibMonaccianSearch(arr, x, n));
    return 0;
}
