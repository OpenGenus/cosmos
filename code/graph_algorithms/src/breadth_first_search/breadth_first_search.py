""" Part of Cosmos by OpenGenus Foundation"""

import collections

"""
    Wrapper function for the print function.
    Used as the default visitFunc for bfs
"""


def visitPrint(i):
    print(i)


"""
    A class representing a undirected graph of nodes.
    An edge can be added between two nodes by calling addEdge
        *This class assumes all edge weights are equal
"""


class Graph:
    def __init__(self):
        self.adjList = collections.defaultdict(set)

    def addEdge(self, node1, node2):
        self.adjList[node1].add(node2)
        self.adjList[node2].add(node1)


"""
    Given a 'start' node and a 'graph', call visitFunc
    sequentially on the current node, and then its children
    and so forth.
    When visiting each node, mark it as visited by adding it to the hashmap.
    Then queue up all of its children to be visited next.
"""


def bfs(start, graph, visitFunc=visitPrint):
    visited = collections.defaultdict(bool)
    queue = collections.deque()

    queue.append(start)

    while len(queue) > 0:
        current = queue.popleft()

        if not visited[current]:
            visited[current] = True
            visitFunc(current)
            for neighbor in graph.adjList[current]:
                queue.append(neighbor)


# Testing the breadth first search implementation
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
    bfs(1, g)

    print("\nTest2:")
    bfs(2, g)

    """Output:
    Test 1:
    1
    2
    3
    4
    5
    6
    7

    Test2:
    2
    1
    4
    5
    3
    6
    7
    """
