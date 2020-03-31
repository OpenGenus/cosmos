// C# program to print DFS traversal  
// from a given graph  
using System; 
using System.Collections.Generic; 
  
// This class represents a directed graph  
// using adjacency list representation  
class Graph 
{ 
    private int V; // No. of vertices  
  
    // Array of lists for  
    // Adjacency List Representation  
    private List<int>[] adj; 
  
    // Constructor  
    Graph(int v) 
    { 
        V = v; 
        adj = new List<int>[v]; 
        for (int i = 0; i < v; ++i) 
            adj[i] = new List<int>(); 
    } 
  
    //Function to Add an edge into the graph  
    void AddEdge(int v, int w) 
    { 
        adj[v].Add(w); // Add w to v's list.  
    } 
  
    // A function used by DFS  
    void DFSUtil(int v, bool[] visited) 
    { 
        // Mark the current node as visited 
        // and print it  
        visited[v] = true; 
        Console.Write(v + " "); 
  
        // Recur for all the vertices  
        // adjacent to this vertex  
        List<int> vList = adj[v]; 
        foreach (var n in vList) 
        { 
            if (!visited[n]) 
                DFSUtil(n, visited); 
        } 
    } 
  
    // The function to do DFS traversal.  
    // It uses recursive DFSUtil()  
    void DFS(int v) 
    { 
        // Mark all the vertices as not visited 
        // (set as false by default in c#)  
        bool[] visited = new bool[V]; 
  
        // Call the recursive helper function  
        // to print DFS traversal  
        DFSUtil(v, visited); 
    } 
  
    // Driver Code 
    public static void Main(String[] args) 
    { 
        Graph g = new Graph(4); 
  
        g.AddEdge(0, 1); 
        g.AddEdge(0, 2); 
        g.AddEdge(1, 2); 
        g.AddEdge(2, 0); 
        g.AddEdge(2, 3); 
        g.AddEdge(3, 3); 
  
        Console.WriteLine("Following is Depth First Traversal " + 
                          "(starting from vertex 2)"); 
  
        g.DFS(2); 
        Console.ReadKey(); 
    } 
} 
