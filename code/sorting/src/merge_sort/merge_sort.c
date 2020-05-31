/*
 * Part of Cosmos by OpenGenus Foundation
 */
#include <stdio.h>
#define max 10

int a[11] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0 };
int b[10];

// Merges two subhalves of a[].
// First sub-half is a[low..mid]
// Second sub-half is a[mid+1..high]

void merging(int low, int mid, int high) {
   int l1, l2, i;

   //Merge the two sub-halves into array b in sorted manner
   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {

      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   //copy the remaining elements of the first sub-array (low-mid) , if any
   while(l1 <= mid)
      b[i++] = a[l1++];

   //copy the remaining elements of the second sub-array (mid+1-high), if any
   while(l2 <= high)
      b[i++] = a[l2++];
   //copy the entire modified array b back into the array a
   for(i = low; i <= high; i++)
      a[i] = b[i];
}

/* low is for left index and high is right index of the
   sub-array of a to be sorted */
void sort(int low, int high) {
   int mid;

   if(low < high) {
      mid = (low + high) / 2;
      //sort first and second halves
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } else {
      return;
   }
}

int main() {
   int i;

   printf("List before sorting\n");

   for(i = 0; i <= max; i++)
      printf("%d ", a[i]);

   sort(0, max);

   printf("\nList after sorting\n");

   for(i = 0; i <= max; i++)
      printf("%d ", a[i]);
}
