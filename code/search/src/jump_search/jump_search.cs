using System; 
public class JumpSearch 
{ 
    public static int jumpSearch(int[] arr, int x) 
    { 
        int n = arr.Length; 
  
        // Finding block size to be jumped 
        int step = (int)Math.Floor(Math.Sqrt(n)); 
  
        // Finding the block where element is 
        // present (if it is present) 
        int prev = 0; 
        while (arr[Math.Min(step, n)-1] < x) 
        { 
            prev = step; 
            step += (int)Math.Floor(Math.Sqrt(n)); 
            if (prev >= n) 
                return -1; 
        } 
  
        // Doing a linear search for x in block 
        // beginning with prev. 
        while (arr[prev] < x) 
        { 
            prev++; 
  
            // If we reached next block or end of 
            // array, element is not present. 
            if (prev == Math.Min(step, n)) 
                return -1; 
        } 
  
        // If element is found 
        if (arr[prev] == x) 
            return prev; 
  
        return -1; 
    } 
  
    // Driver program to test function 
    public static void Main() 
    { 
        int[] arr = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 
                    34, 55, 89, 144, 233, 377, 610}; 
        int x = 55; 
  
        // Find the index of 'x' using Jump Search 
        int index = jumpSearch(arr, x); 
  
        // Print the index where 'x' is located 
        Console.Write("Number " + x + 
                            " is at index " + index); 
    } 
} 
