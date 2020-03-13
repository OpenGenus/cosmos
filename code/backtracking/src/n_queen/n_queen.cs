// C# code to for n Queen problem
using System; 

class NQueen
{ 

	static void breakLine() 
	{ 
		Console.Write("\n---------------------------------\n"); 
	} 
	static int MAX = 10; 

	static int []arr = new int[MAX]; 
	static int no; 

	// Function to check the placement of the queens 
	static void nQueens(int k, int n) 
	{ 

		for (int i = 1; i <= n; i++) 
		{ 
			if (canPlace(k, i)) 
			{ 
				arr[k] = i; 
				if (k == n) 
				{ 
					display(n); 
				} 
				else
				{ 
					nQueens(k + 1, n); 
				} 
			} 
		} 
	} 

	static bool canPlace(int k, int i) 
	{ 
		for (int j = 1; j <= k - 1; j++) 
		{ 
			if (arr[j] == i || 
				(Math.Abs(arr[j] - i) == Math.Abs(j - k))) 
			{ 
				return false; 
			} 
		} 
		return true; 
	} 

	// Function to display the position of the queen 
	static void display(int n) 
	{ 
		breakLine(); 
		Console.Write("Arrangement No. " + ++no); 
		breakLine(); 

		for (int i = 1; i <= n; i++) 
		{ 
			for (int j = 1; j <= n; j++) 
			{ 
				if (arr[i] != j) 
				{ 
					Console.Write("\t_"); 
				} 
				else
				{ 
					Console.Write("\tQ"); 
				} 
			} 
			Console.WriteLine(""); 
		} 

		breakLine(); 
	} 

	public static void Main(String[] args) 
	{ 
		int n = 4; 
		nQueens(1, n); 
	} 
} 
