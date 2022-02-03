# Floyd Warshall algorithm

Floyd-Warshall Algorithm is an algorithm for finding the shortest path between all the pairs of vertices in a weighted graph.
This algorithm works for both the directed and undirected weighted graphs. But, it does not work for the graphs with negative cycles.
Like the Bellman-Ford algorithm or the Dijkstra's algorithm, it computes the shortest path in a graph. However, Bellman-Ford and Dijkstra are both single-source, shortest-path algorithms. This means they only compute the shortest path from a single source. Floyd-Warshall, on the other hand, computes the shortest distances between every pair of vertices in the input graph.

# Time and Space complexity

Time Complexity - There are three loops. Each loop has constant complexities. So, the time complexity of the Floyd-Warshall algorithm is O(n3).

Space Complexity - The space complexity of the Floyd-Warshall algorithm is O(n2).