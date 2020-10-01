#include&lt;iostream&gt; 
#include &lt;list&gt; 
using namespace std; 
   
// a directed graph class 
class DiGraph 
{ 
    int V;    // No. of vertices 
   
    // Pointer to an array containing adjacency lists 
    list&lt;int&gt; *adjList;    
public: 
    DiGraph(int V);  // Constructor 
   
    // add an edge from vertex v to w
    void addEdge(int v, int w);  
   
    // BFS traversal sequence starting with s -&gt;starting node 
    void BFS(int s);   
}; 
   
DiGraph::DiGraph(int V) 
{ 
    this-&gt;V = V; 
    adjList = new list&lt;int&gt;[V]; 
}
 void DiGraph::addEdge(int v, int w) 
{ 
    adjList[v].push_back(w); // Add w to v’s list. 
} 
   
void DiGraph::BFS(int s) 
{ 
    // initially none of the vertices is visited
    bool *visited = new bool[V]; 
    for(int i = 0; i &lt; V; i++) 
        visited[i] = false; 
   
    // queue to hold BFS traversal sequence 
    list&lt;int&gt; queue; 
   
    // Mark the current node as visited and enqueue it 
    visited[s] = true; 
    queue.push_back(s); 
   
    // iterator 'i' to get all adjacent vertices 
    list&lt;int&gt;::iterator i; 
   
    while(!queue.empty()) 
    { 
        // dequeue the vertex 
        s = queue.front(); 
        cout &lt;&lt; s &lt;&lt; " "; 
        queue.pop_front(); 
   
        // get all adjacent vertices of popped vertex and process each if not already visited 
        for (i = adjList[s].begin(); i != adjList[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
}
// main program 
int main() 
{ 
    // create a graph 
    DiGraph dg(5); 
    dg.addEdge(0, 1); 
    dg.addEdge(0, 2); 
    dg.addEdge(0, 3);
    dg.addEdge(1, 2); 
    dg.addEdge(2, 4);
    dg.addEdge(3, 3); 
    dg.addEdge(4, 4);
   
    cout &lt;&lt; "Breadth First Traversal for given graph (with 0 as starting node): "&lt;&lt;endl;
    dg.BFS(0); 
   
    return 0; 
}