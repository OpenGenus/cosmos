class Graph:
    def __init__(self):
        #dictionary where keys are vertices and values are lists of adjacent vertices
        self.vertDict = {}
    def insert_vertex(self, vertex):
        if vertex not in self.vertDict:
            self.vertDict[vertex] = []

    def add_edge(self, vertex1, vertex2, directed=False):
        if vertex1 not in self.vertDict:
            self.insert_vertex(vertex1)
        if vertex2 not in self.vertDict:
            self.insert_vertex[vertex2]

        self.vertDict[vertex1].append(vertex2)
        #if the graph is undirected, add to both's adjacency lists
        if not directed:
            self.vertDict[vertex2].append(vertex1)

    def delete_edge(self, vertex1, vertex2, directed=False):
        if vertex1 in self.vertDict and vertex2 in self.vertDict[vertex1]:
            self.vertDict[vertex1].remove(vertex2)
        if not directed and vertex2 in self.vertDict and vertex1 in self.vertDict[vertex2]:
            self.vertDict[vertex2].remove(vertex1)

    def delete_vertex(self, vertex):
        if vertex in self.vertDict:
            for i in self.vertDict:
                if vertex in self.vertDict[i]:
                    self.vertDict[i].remove(vertex)
            del self.vertDict[vertex]
    
    def get_neighbors(self, vertex):
        return self.vertDict.get(vertex, [])
    
    def printGraph(self):
        for i, j in self.vertDict.items():
            print("{vertex}: {neighbors}")
    

tester = Graph()

tester.insert_vertex("A")
tester.insert_vertex("B")
tester.insert_vertex("C")

tester.add_edge("A", "B")
tester.add_edge("A", "C")
tester.add_edge("B", "C")

tester.printGraph()

print("Neighbors of A:", tester.get_neighbors("A"))

tester.delete_edge("A", "B")

tester.printGraph()

tester.delete_vertex("C")

print("next")

tester.printGraph()
