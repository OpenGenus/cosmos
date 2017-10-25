#include <stdio.h>
/*
 * Part of Cosmos by OpenGenus Foundation
*/
int binarySearch(int arr[], int l, int r, int x)
{
  while (l <= r)
  {
    int m = l + (r-l)/2;
 
    // Check if x is present at mid
    if (arr[m] == x) 
        return m;  
 
    // If x greater, ignore left half  
    if (arr[m] < x) 
        l = m + 1; 
 
    // If x is smaller, ignore right half 
    else
         r = m - 1; 
  }
 
  // if we reach here, then element was not present
  return -1; 
}

void main()
{
   int arr[] = {2, 3, 4, 10, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 10;
   int result = binarySearch(arr, 0, n-1, x);
   if(result==-1)
   
      printf("Element not present in the array");
   else
      printf("Element is present at index %d", result);
   
   
}
