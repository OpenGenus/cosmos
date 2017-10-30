#include <stdio.h>

int ternarySearch(int array[], int left, int right, int x)
{
   if (right >= left) {
     int intvl = (right - left) / 3;
     int leftmid = left + intvl;
     int rightmid = leftmid + intvl;

     if (array[leftmid] == x)
        return leftmid;

     if (array[rightmid] == x)
        return rightmid;

     if (x < array[leftmid]) {
       return ternarySearch(array, left, leftmid, x);
     }
     else if (x > array[leftmid] && x < array[rightmid]) {
       return ternarySearch(array, leftmid, rightmid, x);
     }
     else {
       return ternarySearch(array, rightmid, right, x);
     }
   }
   return -1;
}

int main(void)
{
   int array[] = {1, 2, 3, 5};
   int size = sizeof(array)/ sizeof(array[0]);
   int find = 3;
   printf("Position of %d is %d\n", find, ternarySearch(array, 0, size-1, find));
   return 0;
}
