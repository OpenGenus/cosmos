// C# program for solution of M Coloring problem using backtracking
using System; 

class Mcolor
{ 
	readonly int V = 4; 
	int []color; 

	bool isSafe(int v, int [,]graph, 
				int []color, int c) 
	{ 
		for (int i = 0; i < V; i++) 
			if (graph[v, i] == 1 && c == color[i]) 
				return false; 
		return true; 
	} 

	// A recursive utility function to solve m colouring problem
	
	bool graphColoringUtil(int [,]graph, int m, 
							int []color, int v) 
	{ 
		if (v == V) 
			return true; 

		for (int c = 1; c <= m; c++) 
		{ 
			if (isSafe(v, graph, color, c)) 
			{ 
				color[v] = c; 

				if (graphColoringUtil(graph, m, 
									color, v + 1)) 
					return true; 
				color[v] = 0; 
			} 
		} 

		return false; 
	} 

	bool graphColoring(int [,]graph, int m) 
	{ 
		color = new int[V]; 
		for (int i = 0; i < V; i++) 
			color[i] = 0; 

		if (!graphColoringUtil(graph, m, color, 0)) 
		{ 
			Console.WriteLine("Solution does not exist"); 
			return false; 
		} 
    
		printSolution(color); 
		return true; 
	} 

	void printSolution(int []color) 
	{ 
		Console.WriteLine("Solution Exists: Following" + 
							" are the assigned colors"); 
		for (int i = 0; i < V; i++) 
			Console.Write(" " + color[i] + " "); 
		Console.WriteLine(); 
	} 

	// Driver Code 
	public static void Main(String []args) 
	{ 
		Mcolor Coloring = new Mcolor(); 
		int [,]graph = {{0, 1, 1, 1}, 
						{1, 0, 1, 0}, 
						{1, 1, 0, 1}, 
						{1, 0, 1, 0}}; 
		int m = 3; // Number of colors 
		Coloring.graphColoring(graph, m); 
	} 
} 
