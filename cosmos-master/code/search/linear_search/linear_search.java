/*
 * Part of Cosmos by OpenGenus Foundation
*/
import java.util.*;
class Search
{
    /*
     * Input: an integer array with size in index 0, the element to be searched
     * Output: if found, returns the index of the element else -1
    */
    static int linearSearch(int arr[], int x)
    {
        int size = arr.length;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == x)
                return i;
        }
        return -1;
    }
    
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);//OBject of scanner class to take input
        System.out.println("Enter the size of the array to be searched");
        int n=sc.nextInt();
        int arr[n];
        
        for(int i=0,i<n,i++)//loop to take input
        {
            System.out.println("Enter the element number "+(i+1)+" of the array");
            arr[i]=sc.nextInt();
        }
        
        System.out.println("Enter the number you want to find");
        int find = sc.nextInt();
        System.out.println("Position of "+find+" is "+linearSearch(arr,find));
    }
}
