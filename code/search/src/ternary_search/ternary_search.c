#include <stdio.h>

// Function to perform Ternary Search 
int ternarySearch(int array[], int left, int right, int x)
{
   if (right >= left) {
      
   // Find the leftmid and rightmid 
     int intvl = (right - left) / 3;
     int leftmid = left + intvl;
     int rightmid = leftmid + intvl;
      
   // Check if element is present at any mid 
     if (array[leftmid] == x)
        return leftmid;

     if (array[rightmid] == x)
        return rightmid;

     // As the element is not present at mid, then check on which side it is present
     //Repeat the search operation on the side where it is present 
      
     if (x < array[leftmid]) {
       //The element lies between left and leftmid  
       return ternarySearch(array, left, leftmid, x);
     }
     else if (x > array[leftmid] && x < array[rightmid]) {  
      //The element lies between leftmid and rightmid 
       return ternarySearch(array, leftmid, rightmid, x);
     } 
     else {
      //The element lies between rightmid and right
       return ternarySearch(array, rightmid, right, x);
     }
   }
   //Element not found
   return -1;
}

//Main function
int main(void)
{
   int array[] = {1, 2, 3, 5};
   int size = sizeof(array)/ sizeof(array[0]);
   int find = 3;
   printf("Position of %d is %d\n", find, ternarySearch(array, 0, size-1, find));
   return 0;
}
