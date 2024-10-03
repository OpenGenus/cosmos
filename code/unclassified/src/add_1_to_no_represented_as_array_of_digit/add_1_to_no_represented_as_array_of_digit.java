// Java Program to add 1 to an array 
// representing a number 
import java.io.*; 
  
public class GFG { 
  
    // function to add one and print the array 
    void sum(int[] arr, int n) 
    { 
        int i = n; 
  
        // if array element is less than 9, then 
        // simply add 1 to this. 
        if (arr[i] < 9) { 
            arr[i] = arr[i] + 1; 
            return; 
        } 
  
        // if array element is greater than 9, 
        // replace it with 0 and decrement i 
        arr[i] = 0; 
        i--; 
  
        // recursive function 
        sum(arr, i); 
  
        // If 1 was appended at head 
        // of array then, print it 
        if (arr[0] > 0) 
            System.out.print(arr[0] + ", "); 
  
        // print the array elements 
        // after adding one 
        for (i = 1; i <= n; i++) { 
            System.out.print(arr[i]); 
  
            if (i < n) 
                System.out.print(", "); 
        } 
    } 
  
    // driver code 
    static public void main(String[] args) 
    { 
        GFG obj = new GFG(); 
          
        // number of elements in array 
        int n = 4; 
  
        // array elements, index of array 
        // should be 1 based, hence, 0 is 
        // added here at arr[0] 
        int[] arr = { 0, 1, 9, 3, 9 }; 
  
        // function calling 
        obj.sum(arr, n); 
    } 
} 

// Output :
// 1, 9, 4, 0
