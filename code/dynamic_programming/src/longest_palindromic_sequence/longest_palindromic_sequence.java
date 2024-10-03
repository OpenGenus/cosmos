/* Part of Cosmos by OpenGenus Foundation */
class longest_palindromic_sequence
{ 

	// A utility function to get max of two integers 
	static int max (int x, int y) {
	 return (x > y)? x : y;
	  } 
	
	// Returns the length of the longest 
	// palindromic subsequence in seq 
	static int lps(String seq) { 
		int n = seq.length(); 
		int i, j, cl; 
		// Create a table to store results of subproblems 
		int table[][] = new int[n][n]; 
		
		// Strings of length 1 are palindrome of lentgh 1 
		for (i = 0; i < n; i++) 
			table[i][i] = 1; 
				
			// Build the table. Note that the lower 
			// diagonal values of table are 
			// useless and not filled in the process. 
			// The values are filled in a manner similar 
			// to Matrix Chain Multiplication DP solution
			// cl is length of substring 
			for (cl=2; cl<=n; cl++) 
			{ 
				for (i=0; i<n-cl+1; i++) 
				{ 
					j = i+cl-1; 
					if (seq.charAt(i) == seq.charAt(j) && cl == 2) 
					table[i][j] = 2; 
					else if (seq.charAt(i) == seq.charAt(j)) 
					table[i][j] = table[i+1][j-1] + 2; 
					else
					table[i][j] = max(table[i][j-1], table[i+1][j]); 
				} 
			} 
				
			return table[0][n-1]; 
	} 
		
	/* Driver program to test above functions */
	public static void main(String args[]) { 
		String seq = "bbabcbcab"; // 7: babcbab | bacbcab
		int n = seq.length(); 
		System.out.println("The length of the lps is "+ lps(seq));

		seq = "abbaab"; // 4: abba | baab
		n = seq.length(); 
		System.out.println("The length of the lps is "+ lps(seq)); 

		seq = "opengenus";  // 3: ene | ege | ngn | nen
		n = seq.length(); 
		System.out.println("The length of the lps is "+ lps(seq));  
	} 
} 

