#include <iostream>
#include <vector>

using namespace std;

/*
 * Part of Cosmos by OpenGenus Foundation
*/
int recursiveBinarySearch(vector<int> arr, int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
 
        if (arr[mid] == x)  
            return mid;
         if (arr[mid] > x) 
             return recursiveBinarySearch(arr, l, mid - 1, x);
       
         return recursiveBinarySearch(arr, mid + 1, r, x);
   }
   return -1;
}

int binarySearch(vector<int> arr, int l, int r, int x)
{
  while (l <= r)
  {
    int mid = l + (r-l)/2;

    if (arr[mid] == x) 
        return mid;  

    if (arr[mid] < x) 
        l = mid + 1; 

    else
         r = mid - 1; 
  }
  return -1; 
}
 
int main(void)
{
   vector<int> arr{1, 2, 3, 5};
   int find = 3;
   cout << "Position of " << find << " is " << recursiveBinarySearch(arr, 0, arr.size() - 1, find) << endl;
   cout << "Position of " << find << " is " << binarySearch(arr, 0, arr.size() - 1, find) << endl;
   return 0;
}