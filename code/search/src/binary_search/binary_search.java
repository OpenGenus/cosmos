/*
 * Part of Cosmos by OpenGenus Foundation
*/
class Search
{
    static int recursiveBinarySearch(int arr[], int l, int r, int x)
    {
        if (r>=l)
        {
            int mid = l + (r - l)/2;
 
            if (arr[mid] == x)
               return mid;
 
            if (arr[mid] > x)
               return recursiveBinarySearch(arr, l, mid-1, x);
 
            return recursiveBinarySearch(arr, mid+1, r, x);
        }
        return -1;
    }
    
    static int binarySearch(int arr[], int l, int r, int x)
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
 
    public static void main(String args[])
    {
        int arr[] = {1, 2, 3, 5};
        int size = arr.length;
        int find = 3;
        System.out.println("Position of "+find+" is "+recursiveBinarySearch(arr,0,size-1,find));
        System.out.println("Position of "+find+" is "+binarySearch(arr,0,size-1,find));
    }
}