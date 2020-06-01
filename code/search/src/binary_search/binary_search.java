/*
 * Part of Cosmos by OpenGenus Foundation
*/
class Search
{//Implementation of Binary Search in java
    static int recursiveBinarySearch(int arr[], int l, int r, int x)
    {//recursive function that returns the index of element x if it is present in arr[],else returns -1
        if (r>=l)
        {
            int mid = l + (r - l)/2; //finding out the middle index
 
            if (arr[mid] == x)
               return mid; //If x is present at the middle
 
            if (arr[mid] > x) //If x is smaller than the element at middle,then it might be present in the left of middle.
               return recursiveBinarySearch(arr, l, mid-1, x);
 
            return recursiveBinarySearch(arr, mid+1, r, x); //else the element can only be present in the right subarray
        }
        return -1; //-1 is returned if the element x is not present in the array
    }
    
    static int binarySearch(int arr[], int l, int r, int x)
    {//Iterative implementation of Binary Search
        while (l <= r) //the loop runs till the low index(l) is less than or equal to the high index(r)
        {
            int mid = l + (r-l)/2; //Calculating middle index

            if (arr[mid] == x) 
                return mid;  //if the element x is present on middle index

            if (arr[mid] < x)  //If x greater, ignore left half
                l = mid + 1; 

            else
                r = mid - 1; // If x is smaller, ignore right half 
        }
        return -1; //if the element is not present in the array,-1 is returned
    }
 
    public static void main(String args[])
    {
        int arr[] = {1, 2, 3, 5};
        int size = arr.length; //stores the length of arr[]
        int find = 3; //Element to be searched
        System.out.println("Position of "+find+" is "+recursiveBinarySearch(arr,0,size-1,find));
        System.out.println("Position of "+find+" is "+binarySearch(arr,0,size-1,find));
    }
}
