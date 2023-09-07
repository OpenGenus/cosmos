<h1>Count Inversions</h1>
  
## Problem Statement
For a given integer array/list 'ARR' of size 'N', find the total number of 'Inversions' that may exist.
An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

1. 'ARR[i] > 'ARR[j]' 
2. 'i' < 'j'

## Intution 
If an array is sorted, the array inversions are 0, and if reverse sorted, the array inversions are maximum.

But what if we have an unsorted array?

To sort the array, we will use mergeSort. In mergeSort, we will deep in one element, compare two elements, and put it in a new array in sorted order. By doing this for log(N) time, we will get the sorted array, and while comparing the two array elements, we will add some more lines of code such that it will count the inversion of the smaller array and slowly it will count for larger and larger array.

## Code
```
  public class Solution {
      public static long getInversions(long arr[], int n) {
          // Write your code here.
          return divide(arr,new long[n],0,n-1);
      }

      public static long divide(long[] arr,long[] temp,int l,int h) {
          long inv_count=0;
          if(l<h) {
              int mid=(l+h)>>1;
              inv_count+=divide(arr,temp,l,mid);
              inv_count+=divide(arr,temp,mid+1,h);

            inv_count+=merge(arr,temp,l,mid+1,h);
          }
          return inv_count;
      }

      public static long merge(long[] arr,long[] temp,int l,int mid,int r) {
          int i=l;
          int j=mid;
          int k=l;
          long ans=0;
          while((i<=mid-1) && (j<=r)) {
              if(arr[i] <= arr[j])
                  temp[k++] = arr[i++];
              else {
                  temp[k++]=arr[j++];
                  ans+=(mid-i);
              }
          }

          while(i<=mid-1)
              temp[k++] = arr[i++];
          while(j<=r)
              temp[k++]=arr[j++];
          for(i=l;i<=r;i++)
              arr[i]=temp[i];
          return ans;
      }
  }
```
