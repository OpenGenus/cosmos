from collections import defaultdict

# Part of Cosmos by OpenGenus Foundation
class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = []

    def addEdge(self, u, v, w):
        self.graph.append([u, v, w])

    def find(self, parent, i):
        if parent[i] == i:
            return i
        return self.find(parent, parent[i])

    def union(self, parent, rank, x, y):
        xroot = self.find(parent, x)
        yroot = self.find(parent, y)

        if rank[xroot] < rank[yroot]:
            parent[xroot] = yroot
        elif rank[xroot] > rank[yroot]:
            parent[yroot] = xroot
        else:
            parent[yroot] = xroot
            rank[xroot] += 1

    def KruskalMST(self):
        result = []
        i, e = 0, 0

        self.graph = sorted(self.graph, key=lambda item: item[2])

        parent = []
        rank = []

        for node in range(self.V):
            parent.append(node)
            rank.append(0)

        while e < self.V - 1:
            u, v, w = self.graph[i]
            i = i + 1
            x = self.find(parent, u)
            y = self.find(parent, v)

            if x != y:
                e = e + 1
                result.append([u, v, w])
                self.union(parent, rank, x, y)

        print("Constructed MST :")
        print("Vertex A    Vertex B  Weight")
        for u, v, weight in result:
            print("    %d          %d        %d" % (u, v, weight))


# vetx = int(input("Enter no. of vertices :"))
eegde = int(input("Enter no. of edges :"))

g = Graph(eegde - 1)

print(
    "For each edge input (Source vertex , Destination vertex , Weight of the edge ) :"
)
for x in range(eegde):
    qq, xx, yy = map(int, input().split(" "))
    g.addEdge(qq, xx, yy)

g.KruskalMST()
