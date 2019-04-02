from collections import defaultdict


class Graph:
    def __init__(self, vertices):
        self.graph = defaultdict(list)
        self.V = vertices

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def topologicalSortUtil(self, v, visited, stack):

        visited[v] = True  # Mark current node as visited

        for i in self.graph[v]:  # traversing adjacent nodes
            if visited[i] == False:
                self.topologicalSortUtil(i, visited, stack)

        stack.insert(0, v)  # pushing current node to stack

    def topologicalSort(self):

        visited = [False] * self.V
        stack = []

        for i in range(self.V):
            if visited[i] == False:
                self.topologicalSortUtil(i, visited, stack)

        print(stack)


g = Graph(4)
g.addEdge(0, 2)
g.addEdge(0, 3)
g.addEdge(2, 1)
g.addEdge(1, 3)
g.addEdge(2, 3)

print("Topological Sort of the given graph")
g.topologicalSort()
