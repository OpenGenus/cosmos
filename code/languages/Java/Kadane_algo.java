import java.util.Scanner; 
class Kadane_Algo{ 
    public static void main (String[] args) { 
        int[] array = {-2, -3, 4, -1, -2, 1, 5, -3};
        int size = array.length; 
        int maximum_overall = Integer.MIN_VALUE, max_ending_here = 0; 
  
        for (int i = 0; i < size; i++) { 
            max_ending_here = max_ending_here + array[i]; 
            if (maximum_overall < max_ending_here) 
                maximum_overall = max_ending_here; 
            if (max_ending_here < 0) 
                max_ending_here = 0; 
        } 
        System.out.println("Maximum continuous sum of subarray is " + maximum_overall); 
    } 
} 

OUTPUT
Maximum continuous sum of subarray is 7
