#include <stdio.h>
#include <stdbool.h>

/* A utility function to print solution */
void printSolution(int color[], int V) 
{ 
    printf("Following are the assigned colors for %d vertices:%n", &V); 
    
    for(int i = 0; i < V; i++) 
      	printf(" %d ", color[i]); 
    
    printf("\n"); 
} 

/* A utility function to check if the current color assignment is safe for vertex v*/
bool isSafe (int v, int *graph, int V, int color[], int c) 
{ 
    for (int i = 0; i < V; i++) 
        if (*((graph+v*V) + i) && c == color[i]) 
            return false; 
    return true; 
} 
  
/* A recursive utility function to solve m coloring problem */
bool graphColoringUtil(int *graph, int V, int m, int color[], int v) 
{ 
    /* base case: If all vertices are assigned a color then 
       return true */
    if (v == V) 
        return true; 
  
    /* Consider this vertex v and try different colors */
    for (int c = 1; c <= m; c++) 
    { 
        /* Check if assignment of color c to v is fine*/
        if (isSafe(v, (int*)graph, V, color, c)) 
        { 
           color[v] = c; 
  
           /* recur to assign colors to rest of the vertices */
           if (graphColoringUtil (graph, V, m, color, v+1) == true) 
             return true; 
  
            /* If assigning color c doesn't lead to a solution 
               then remove it */
           color[v] = 0; 
        } 
    } 
  
    /* If no color can be assigned to this vertex then return false */
    return false; 
} 
  
/* This function solves the m Coloring problem using Backtracking.*/
bool graphColoring(int *graph, int V, int m) 
{ 
    // Initialize the color array to 0
    int color[V]; 
    for (int i = 0; i < V; i++) 
       color[i] = 0; 
  
    // Calling graphColoringUtil() for vertex 0 
    if (graphColoringUtil((int*)graph, V, m, color, 0) == false) 
    	return false; 
    
    printSolution(color,V)
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

 
int main() 
{
	// Number of vertices present in the graph
    int V,m;
    scanf("%d", &V);

    // Enter 1 if there is an edge b/w two vertices else Enter 0
    int graph[V][V];

    for(int i=0; i<V; i++)
    	for(int j=0; j<V; j++)
    		scanf("%d",&graph[i][j]);
    
    // Enter number of colors to be added
    scanf("%d", &m);

    bool res = graphColoring (&graph[0][0], V, m); 

    if(res==false)
    	printf("Solution does not exist");
    
    return 0; 
} 
