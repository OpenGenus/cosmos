""" Part of Cosmos by OpenGenus Foundation"""

import collections


class Graph:
    def __init__(self):
        self.adjList = collections.defaultdict(set)

    def addEdge(self, node1, node2):
        self.adjList[node1].add(node2)
        self.adjList[node2].add(node1)


def dfsHelper(current, graph, visited, visitFunc):
    if visited[current]:
        return

    visited[current] = True

    visitFunc(current)

    for neighbor in graph.adjList[current]:
        dfsHelper(neighbor, graph, visited, visitFunc)


def dfs(current, graph, visitFunc):
    visited = collections.defaultdict(bool)
    dfsHelper(current, graph, visited, visitFunc)


def visitPrint(i):
    print(i)


# Testing the depth first search implementation
if __name__ == "__main__":

    # Testing on this tree
    #      1
    #     / \
    #    /   \
    #   2     3
    #  / \   / \
    # 4   5 6   7

    g = Graph()
    g.addEdge(1, 2)
    g.addEdge(1, 3)
    g.addEdge(2, 4)
    g.addEdge(2, 5)
    g.addEdge(3, 6)
    g.addEdge(3, 7)

    print("Test 1:")
    dfs(1, g, visitPrint)

    print("\nTest2:")
    dfs(2, g, visitPrint)

    """Output:
    Test 1:
    1
    2
    4
    5
    3
    6
    7

    Test2:
    2
    1
    3
    6
    7
    4
    5
    """
