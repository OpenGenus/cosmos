class Graph:
    """
    Adjacency Matrix representation in Python
    """

    # Initialize the matrix
    def __init__(self, size):
        self.adjMatrix = [[0 for _ in range(size)] for _ in range(size)]
        self.size = size

    # adding edge from vertex v1 to v2
    def addEdge(self, v1, v2):
        self.adjMatrix[v1][v2] = 1
        self.adjMatrix[v2][v1] = 1

    # deleting edge
    def delEdge(self, v1, v2):
        self.adjMatrix[v1][v2] = 0
        self.adjMatrix[v2][v1] = 0

    # length of graph
    def __len__(self):
        return self.size

    # printing matrix
    def printMatrix(self):
        for row in self.adjMatrix:
            print(*row)
            print


def main():
    graph = Graph(5)  # init graph of size 5
    graph.addEdge(0, 1)
    graph.addEdge(0, 2)
    graph.addEdge(1, 2)
    graph.addEdge(2, 0)
    graph.addEdge(2, 3)

    graph.printMatrix()


if __name__ == "__main__":
    main()
