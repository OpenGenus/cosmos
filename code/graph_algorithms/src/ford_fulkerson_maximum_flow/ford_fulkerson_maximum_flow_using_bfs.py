"""
Part of Cosmos by OpenGenus Foundation
"""

from collections import defaultdict

# This class represents a directed graph using adjacency matrix representation
class Graph:
    def __init__(self, graph):
        self.graph = graph  # residual graph
        self.ROW = len(graph)
        # self.COL = len(gr[0])

    """Returns true if there is a path from source 's' to sink 't' in
    residual graph. Also fills parent[] to store the path """

    def BFS(self, s, t, parent):

        # Mark all the vertices as not visited
        visited = [False] * (self.ROW)

        # Create a queue for BFS
        queue = []

        # Mark the source node as visited and enqueue it
        queue.append(s)
        visited[s] = True

        # Standard BFS Loop
        while queue:

            # Dequeue a vertex from queue and print it
            u = queue.pop(0)

            # Get all adjacent vertices of the dequeued vertex u
            # If a adjacent has not been visited, then mark it
            # visited and enqueue it
            for ind, val in enumerate(self.graph[u]):
                if visited[ind] == False and val > 0:
                    queue.append(ind)
                    visited[ind] = True
                    parent[ind] = u

        # If we reached sink in BFS starting from source, then return
        # true, else false
        return True if visited[t] else False

    # Returns tne maximum flow from s to t in the given graph
    def FordFulkerson(self, source, sink):

        # This array is filled by BFS and to store path
        parent = [-1] * (self.ROW)

        max_flow = 0  # There is no flow initially

        # Augment the flow while there is path from source to sink
        while self.BFS(source, sink, parent):

            # Find minimum residual capacity of the edges along the
            # path filled by BFS. Or we can say find the maximum flow
            # through the path found.
            path_flow = float("Inf")
            s = sink
            while s != source:
                path_flow = min(path_flow, self.graph[parent[s]][s])
                s = parent[s]

            # Add path flow to overall flow
            max_flow += path_flow

            # update residual capacities of the edges and reverse edges
            # along the path
            v = sink
            while v != source:
                u = parent[v]
                self.graph[u][v] -= path_flow
                self.graph[v][u] += path_flow
                v = parent[v]

        return max_flow


# Create a graph given in the above diagram

print("Enter the number of vertices: ", end="")
m = int(input())
matrix = []
for i in range(0, m):
    matrix.append([])
    for j in range(0, m):
        print("Enter the edge value from " + str(i) + " to " + str(j) + ": ", end="")
        temp = int(input())
        matrix[i].append(temp)
print("\nthe matrix is,\n")
for i in range(0, m):
    for j in range(0, m):
        print(matrix[i][j], " ", end="")
    print("\n")
print("Enter the source: ", end="")
source = int(input())
print("Enter the sink: ", end="")
sink = int(input())

print("The maximum possible flow is %d " % g.FordFulkerson(source, sink))
