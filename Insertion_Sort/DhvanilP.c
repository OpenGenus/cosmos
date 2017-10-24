#include <stdio.h>
#include <math.h>
 
int main()
{
    int arr[] = {8,10,13,45,23,4};
    int n = sizeof(arr)/sizeof(arr[0]);
	
	int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1; 
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
   
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
 
    return 0;
}