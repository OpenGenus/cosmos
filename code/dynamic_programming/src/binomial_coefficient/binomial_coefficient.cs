// C# Code for Dynamic Programming | 
using System; 

class GFG { 
	
	// Returns value of Binomial 
	// Coefficient C(n, k) 
	static int binomialCoeff(int n, int k) 
	{ 
		
		// Base Cases 
		if (k == 0 || k == n) 
			return 1; 
		
		// Recur 
		return binomialCoeff(n - 1, k - 1) + 
					binomialCoeff(n - 1, k); 
	} 
	
	/* Driver program to test above function */
	public static void Main() 
	{ 
		int n = 5, k = 2; 
		Console.Write("Value of C(" + n + ","
							+ k + ") is " + 
						binomialCoeff(n, k)); 
	} 
} 
 
