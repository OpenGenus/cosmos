import java.util.Scanner;


/* A utility function to print solution */

public class mColoringProblem{

    int color[];

    void printSolution(int color[], int V) 
    { 
        System.out.println("Following are the assigned colors for " + V + " vertices:"); 
    
        for(int i = 0; i < V; i++) 
      	     System.out.print(color[i] + " "); 
    
        System.out.println();
    } 

    /* A utility function to check if the current color assignment is safe for vertex v*/
    boolean isSafe (int v, int graph[][], int V, int color[], int c) 
    { 
        for (int i = 0; i < V; i++) 
            if (graph[v][i]==1 && c == color[i]) 
                return false; 
        return true; 
    } 
  
    /* A recursive utility function to solve m coloring problem */
    boolean graphColoringUtil(int graph[][], int V, int m, int color[], int v) 
    { 
        /* base case: If all vertices are assigned a color then 
           return true */
        if (v == V) 
            return true; 
      
        /* Consider this vertex v and try different colors */
        for (int c = 1; c <= m; c++) 
        { 
            /* Check if assignment of color c to v is fine*/
            if (isSafe(v, graph, V, color, c)) 
            { 
               color[v] = c; 
      
               /* recur to assign colors to rest of the vertices */
               if (graphColoringUtil (graph, V, m, color, v+1) == true) 
                 return true; 
      
                /* If assigning color c doesn't lead to a solution 
                   then remove it i.e. Backtrack*/
               color[v] = 0; 
            } 
        } 
      
        /* If no color can be assigned to this vertex then return false */
        return false; 
    } 
      
    /* This function solves the m Coloring problem using Backtracking.*/
    boolean graphColoring(int graph[][], int V, int m) 
    { 
        // Initialize the color array to 0
        color = new int[V];
        for (int i = 0; i < V; i++) 
           color[i] = 0; 
      
        // Calling graphColoringUtil() for vertex 0 
        if (graphColoringUtil(graph, V, m, color, 0) == false) 
        	return false; 
        
        printSolution(color,V);
        return true; 
    } 

    /* Input:

    For following graph
          (3)---(2) 
           |   / | 
           |  /  | 
           | /   | 
          (0)---(1) 
    4
    0 1 1 1 1 0 1 0 1 1 0 1 1 0 1 0
    3

    Output:
    Following are the assigned colors for 4 vertices:
    1 2 3 2
    */

     
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        mColoringProblem clr = new mColoringProblem(); 
        
        int V = sc.nextInt();

        // Enter 1 if there is an edge b/w two vertices else Enter 0
        int[][] graph = new int[V][V];

        for(int i=0; i<V; i++)
        	for(int j=0; j<V; j++)
        		graph[i][j] = sc.nextInt();
        
        // Enter number of colors to be added
        int m = sc.nextInt();

        boolean res = clr.graphColoring (graph, V, m); 

        if(res==false)
        	System.out.println("Solution does not exist");

    } 

}
