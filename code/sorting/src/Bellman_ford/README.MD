# Bellman Ford Algorithm

The Bellman-Ford algorithm is a very popular algorithm used to find the shortest path from one node to all the other nodes in a weighted graph.

The Bellman-Ford algorithm is a single-source shortest path algorithm. This means that, given a weighted graph, this algorithm will output the shortest distance from a selected node to all other nodes.

It is very similar to the Dijkstra Algorithm. However, unlike the Dijkstra Algorithm, the Bellman-Ford algorithm can work on graphs with negative-weighted edges. This capability makes the Bellman-Ford algorithm a popular choice.

# Algorithm

Bellman ford algorithm follows the dynamic programming approach by overestimating the length of the path from the starting vertex to all other vertices. And then it starts relaxing the estimates by discovering the new paths which are shorter than the previous ones. This process is followed by all the vertices for N-1 times for finding the optimized result. 

1) Initializing the source vertex with distance to itself as 0 and all other vertices as infinity. Creating the array with size N

2) Calculate the shortest distance from the source vertex. Following this process for N-1 times where N is the number of vertices in the graph

              For relaxing the path lengths for the vertices for each edge m-n:

              if distance[n] > distance[m] + weight of edge mn, then

              distance[n] = distance[m] + weight of edge mn

3) Even after minimizing the path lengths for each vertex after N-1 times, if we can still relax the path length where distance[n] > distance[m] + weight of edge mn then we can say that the graph contains the negative edge cycle.


# Pesudocode 

 BellmanFord(Edges[][], src, V): 
    dis[] = new int[V]
 
    For i = 1 to V :
        dis[i] = INF     // (INF=Very Large Value)

    dis[src] = 0
    For i = 1 to V-1 :
        For j 1 to Edges.length:
        u = Edges[j][0]
        v = Edges[j][1]
        wt = Edges[j][2]
        dis[v] = MIN(dis[u]+wt,dis[v])

    For i = 1 to Edges.length:
        u = Edges[i][0]
        v = Edges[i][1]
        wt = Edges[i][2]
        If(dis[v] > dis[u]+wt)
            Print "Negative Weight cycle exists."

    Return dis

# Drawback 

The only limitation of the bellman ford algorithm is that it does not work with a graph having a negative edge cycle.  

# Complexity

Time Complexity - 
 
 Best Case Complexity	O(E)
Average Case Complexity	O(VE)
Worst Case Complexity	O(VE)

Space Complexity - 

the space complexity is O(V).