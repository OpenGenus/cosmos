#include <stdio.h>

int getInvCount(int arr[], int n)
{
  int inv_count = 0;
  for (int i = 0; i < n - 1; i++)
    for (int j = i+1; j < n; j++)
      if (arr[i] > arr[j])
        inv_count++;
 
  return inv_count;
}
 
int main(int argv, char** args)
{
  int n;
  scanf("%d",&n);
  int arr[n],i;
  for(i=0;i<n;i++)
  scanf("%d",&arr[i]);
  printf(" Number of inversions are %d \n", getInvCount(arr, n));
  return 0;
}
