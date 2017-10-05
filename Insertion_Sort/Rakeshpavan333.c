#include <stdio.h>
 int insertion_Sort(int arr[], int n) 
{
  int i,temp,j;
   for (i = 1; i < n; i++)
   {
       temp = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > temp)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = temp;
   }
}

int main() 
{
	int arr[100];
  int n,i;
  printf("\n Enter the Size of the array : ");
  scanf("%d", &n);
  printf("\n Enter the array elements ");
  for(i=0;i<n;++i)
      scanf("%d", &arr[i]);     
  insertion_Sort(arr,n);
  
  printf("\n The sorted array is : ");
  for(i=0;i<n;++i)
      printf(" %d ",arr[i]);

  return 0;
}
