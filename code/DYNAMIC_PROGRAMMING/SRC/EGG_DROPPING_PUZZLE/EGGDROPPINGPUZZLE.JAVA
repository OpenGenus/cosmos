
//Dynamic Programming solution for the Egg Dropping Puzzle
 /* Returns the minimum number of attempts
  needed in the worst case for a eggs and b floors.*/
import java.util.*;

public class EggDroppingPuzzle {    
	// min trials with a eggs and b floors 
	private static int minTrials(int a, int b) {
		int eggFloor[][] = new int[a + 1][b + 1];
	 	int result, x;
		
		for (int i = 1; i <= a; ++i) {
                	eggFloor[i][0] = 0;   // Zero trial for zero floor.
                 	eggFloor[i][1] = 1;   // One trial for one floor 
		}
        	// j trials for only 1 egg	
        	for (int j = 1; j <= b; ++j) {
	        	eggFloor[1][j] = j;
		}
   		for (int i = 2; i <= a; ++i) {
            		for (int j = 2; j <= b; ++j) {
	        		eggFloor[i][j] = Integer.MAX_VALUE;
	        		for (x = 1; x <= j; ++x) {   
	                	// get worst case from:case in which egg break (eggFloor[i-1][x-1]) and  case in which egg does not break (eggFloor[i][j-x]).
		       	 		result = 1 + Math.max(eggFloor[i - 1][x - 1], eggFloor[i][j - x]);  
					//choose min of all values for particular x
        		    		if (result < eggFloor[i][j])
			        		eggFloor[i][j] = result;
		        	} 
	    		}               
        	}        
		return eggFloor[a][b];
    	}
		
	//testing the program
   	 public static void main(String args[]) {   
       	Scanner sc = new Scanner(System.in);
		System.out.println("Enter no. of eggs");
	
		int a = Integer.parseInt(sc.nextLine());
		System.out.println("Enter no. of floors");
		
        	int b = Integer.parseInt(sc.nextLine());
        	//result outputs min no. of trials in worst case for a eggs and b floors
        	int result = minTrials(a, b);
        	System.out.println("Minimum number of attempts needed in Worst case with a eggs and b floor are: " + result); 
    	}
}  
