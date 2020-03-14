// C# program to find an element x in a sorted array using Exponential search.
using System;
// Part of Cosmos by OpenGenus Foundation
class ExponentialSearch {
   
    // Returns position of first ocurrence of x in array
    static int exponentialSearch(int[] arr, int n, int x) {
   
        // If x is present at firt location itself
        if (arr[0] == x) {
            return 0;
        }
      
        // Find range for binary search by
        // repeated doubling
        int i = 1;

        while (i < n && arr[i] <= x) {
            i = i * 2;
        }
      
        //  Call binary search for the found range.
        return Arrays.binarySearch(arr, i/2, Math.min(i, n), x);
    }
     
    // Driver method
    public static void Main(String[] args)
    {
        int[] arr = {4, 91, 66, 89, 54, 2, 3};
        int x = 66;
        int result = exponentialSearch(arr, arr.length, x);

        if( result < 0 ) {
            Console.Write("Element is not present in array");    
        }
        else {
            Console.Write("Element is present at index " + result);
        }
    }
}
