import java.util.*;
import java.lang.*;
import java.io.*;

class stfood
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		while (t-- >0){
		    int n = s.nextInt();
		    int maxprofit = 0;
		    for (int i = 0; i < n ; i++){
		        int stores = s.nextInt();
		        int p = s.nextInt();
		        int v = s.nextInt();
		        int profit = (p/(stores+1)) * v;
		        
		        if (maxprofit < profit){
		            maxprofit = profit;
		        }
		    }
		    
		    System.out.println(maxprofit);
		}
	}
}

/*
TEST CASES

INPUT
2
3
4 6 8
2 6 6
1 4 3
1
7 7 4

OUTPUT
12
0
*/