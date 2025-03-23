class Node:
    """
    creating a node to connet
    to our main adjacency list
    """

    def __init__(self, data):
        self.vertex = data
        self.next = None


class Graph:
    """
    this class represents a graph as adjacency
    lists. Size of the array will be the no.
    of the vertices "V"
    """

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [None] * self.V

    def addEdge(self, src, dest):
        # Adding the node to the source node
        node = Node(dest)
        node.next = self.graph[src]
        self.graph[src] = node

        # Adding the source node to the destination
        # as a undirected graph
        node = Node(src)
        node.next = self.graph[dest]
        self.graph[dest] = node

    # printing the graph
    def printGraph(self):
        for i in range(self.V):
            print("Adjacency list of vertex {}\n head".format(i), end="")
            temp = self.graph[i]
            while temp:
                print(" -> {}".format(temp.vertex), end="")
                temp = temp.next
            print


def main():
    graph = Graph(5)  # graph of 5 vertices
    graph.addEdge(0, 1)
    graph.addEdge(0, 4)
    graph.addEdge(1, 2)
    graph.addEdge(1, 3)
    graph.addEdge(1, 4)
    graph.addEdge(2, 3)
    graph.addEdge(3, 4)

    graph.printGraph()


if __name__ == "__main__":
    main()
