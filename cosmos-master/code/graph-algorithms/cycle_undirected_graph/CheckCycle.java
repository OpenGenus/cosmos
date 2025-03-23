// Java Program to detect cycle in an undirected graph.
// This program performs  DFS traversal on the given graph 
// represented by a adjacency matrix 
// to check for cycles in the graph

import java.util.*;
import java.lang.*;
import java.io.*;
 
public class CheckCycle
{
    private Stack <Integer> stack;
    private int adjacencyMatrix[][];
 
    public CheckCycle() 
    {
        stack = new Stack<Integer>();
    }
 
 	//DFS function
    public void dfs(int adjacency_matrix[][], int source)
    {
        int number_of_nodes = adjacency_matrix[source].length - 1;
 
        adjacencyMatrix = new int[number_of_nodes + 1][number_of_nodes + 1];
        for (int sourcevertex = 1; sourcevertex <= number_of_nodes; sourcevertex++)
        {
            for (int destinationvertex = 1; destinationvertex <= number_of_nodes; destinationvertex++)
            {
                adjacencyMatrix[sourcevertex][destinationvertex] = adjacency_matrix[sourcevertex][destinationvertex];
            }
        }
 		
 		//Allocating memory for visited nodes
        int visited[] = new int[number_of_nodes + 1];		
        int element = source;		
        int destination = source;			
        visited[source] = 1;		
        stack.push(source);
 
        while (!stack.isEmpty())
        {
            element = stack.peek();
            destination = element;	
	    while (destination <= number_of_nodes)
	    {
                if (adjacencyMatrix[element][destination] == 1 && visited[destination] == 1)
                {
                    if (stack.contains(destination))
                    {	
                        System.out.println("The Graph contains cycle");
                        return;	
                    }
                }
 
              	if (adjacencyMatrix[element][destination] == 1 && visited[destination] == 0)
	        {
                    stack.push(destination);
                    visited[destination] = 1;
                    adjacencyMatrix[element][destination] = 0;
                    element = destination;
                    destination = 1;
	            continue;
                }
                destination++;
	    }
            stack.pop();	
        }	
    }
 
 	//The Main function
    public static void main(String[] args)
    {
        int number_of_nodes, source;
        Scanner scanner = new Scanner(System.in);
 	try
        {
	    System.out.println("Enter the number of nodes in the graph");
            number_of_nodes = scanner.nextInt();
 
	    int adjacency_matrix[][] = new int[number_of_nodes + 1][number_of_nodes + 1];
	    System.out.println("Enter the adjacency matrix");
	    for (int i = 1; i <= number_of_nodes; i++)
	        for (int j = 1; j <= number_of_nodes; j++)
                    adjacency_matrix[i][j] = scanner.nextInt();
 
            System.out.println("Enter the source for the graph");
            source = scanner.nextInt(); 
 
            CheckCycle checkCycle = new CheckCycle();
            checkCycle.dfs(adjacency_matrix, source);
 
        }catch(InputMismatchException inputMismatch)
        {
            System.out.println("Wrong Input format");
        }	
    }	
}
/*
Sample Case ::
Input ::

5
0 0 0 1 0
1 0 1 0 0
0 0 0 0 0
0 1 0 0 1 
0 0 1 0 0 
1

Output ::

The Graph contains cycle
*/