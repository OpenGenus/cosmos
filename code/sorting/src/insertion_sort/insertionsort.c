#include<stdio.h>
#include<stdlib.h>
int main()
{
  int n;
  printf("Enter number of elements in an array:");
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++){
      scanf("%d",&a[i]);
  }
  int i, j, key;
  for(i=1; i<n; i++)
  {
    key = a[i];
    j = i-1;
  
    while(j>=0 && key < a[j])
    {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;
  }
  for(i = 0; i < n; i++)
  {
    printf("%d ",a[i]);
  }
  return (0);
}