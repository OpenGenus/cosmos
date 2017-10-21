/*
 * Part of Cosmos by OpenGenus Foundation
*/
import java.util.*;
public class LinearSearch
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
    
    // A recursive implementation of linear search
    static int recLinSearch(int[] list, int key) {
        return recLinSearch(list, key, 0);
    }
    
    private static int recLinSearch(int[] list, int key, int index) {
        if (index == list.length) return -1; // key not found at all
        if (key == list[index]) return index; // key found at current index
        return recLinSearch(list, key, index + 1); // else, keep moving through indices
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
        System.out.println("Position of "+find+" is "+recLinSearch(arr,find));
    }
}
