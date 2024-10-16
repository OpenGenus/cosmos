#include <stdio.h>
/*
 * Part of Cosmos by OpenGenus Foundation
*/
// A recursive binary search function. It returns 
// location of x in given array arr[l..r] is present, 
// otherwise -1 
int recursiveBinarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x)  
            return mid;
        // If element is smaller than mid, then 
        // it can only be present in left subarray
         if (arr[mid] > x) 
             return recursiveBinarySearch(arr, l, mid-1, x);
        // Else the element can only be present 
        // in right subarray 
         return recursiveBinarySearch(arr, mid+1, r, x);
   }
   // We reach here when element is not 
   // present in array 
   return -1;
}
// A iterative binary search function. It returns 
// location of x in given array arr[l..r] is present, 
// otherwise -1 
int binarySearch(int arr[], int l, int r, int x)
{
  while (l <= r)
  {
    int mid = l + (r-l)/2;
    // If the element is present at the middle 
    // itself 
    if (arr[mid] == x) 
        return mid;  
     // If element is greater than mid, then 
    // it can only be present in right subarray
    if (arr[mid] < x) 
        l = mid + 1; 
    // Else the element can only be present 
    // in right subarray
    else
         r = mid - 1; 
  }
   // We reach here when element is not 
   // present in array 
   return -1; 
}
 
int main(void)
{
   int arr[] = {1, 2, 3, 5};
   int size = sizeof(arr)/ sizeof(arr[0]);
   int find = 3;
   //Printing the position of element using recursive binary search
   printf("Position of %d is %d\n", find, recursiveBinarySearch(arr, 0, size-1, find));
   //Printing the position of element using iterative binary search
   printf("Position of %d is %d\n", find, binarySearch(arr, 0, size-1, find));
   return 0;
}
