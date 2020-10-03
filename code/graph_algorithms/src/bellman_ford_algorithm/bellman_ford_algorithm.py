# part of cosmos by OpenGenus Foundation

from collections import defaultdict

# Part of Cosmos by OpenGenus Foundation
class Graph:
    def __init__(self, vertices):
        self.V = vertices  # # of vertices
        self.graph = []

        # add edge to graph

    def addEdge(self, u, v, w):
        self.graph.append([u, v, w])

        # print solution

    def printArr(self, dist):
        print("Vertex Distance from Source ")
        for i in range(self.V):
            print("%d -> %d" % (i, dist[i]))

            # main function for bellman ford algo. Also detects negative weight cycles

    def bellmanFord(self, src):

        # init all distances from source to all as INFINITE
        dist = [float("Inf")] * self.V
        dist[src] = 0

        # relax all edges |V|-1 times.
        for i in range(self.V - 1):
            # update dist value and parent index of adjacent values of picked vertex.
            # consider those which are still in queue.
            for u, v, w in self.graph:
                if dist[u] != float("Inf") and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w

                    # check for negative weight cycles. If path obtained from above step (shortest distances)
                    # is shorter, there's a cycle. So quit.
        for u, v, w in self.graph:
            if dist[u] != float("Inf") and dist[u] + w < dist[v]:
                print("Negative Cycles !")
                return

                # print distances
        self.printArr(dist)


# dry run

if __name__ == "__main__":
    g = Graph(5)
    g.addEdge(0, 1, -1)
    g.addEdge(0, 2, 4)
    g.addEdge(1, 2, 3)
    g.addEdge(1, 3, 2)
    g.addEdge(1, 4, 2)
    g.addEdge(3, 2, 5)
    g.addEdge(3, 1, 1)
    g.addEdge(4, 3, -3)
    g.bellmanFord(0)
