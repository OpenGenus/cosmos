# python3
# Python Program for union-find algorithm to detect cycle in an undirected graph

import sys
from collections import defaultdict


# this function initializes all single element sets
def make_set(n):
    parent = [0] * n
    rank = [0] * n
    for i in range(n):
        parent[i] = i
        rank[i] = 0
    return parent, rank


# A function to find the ID of an element i
def find(parent, _i):
    if parent[_i] != _i:
        # path compression
        parent[_i] = find(parent, parent[_i])
    return parent[_i]


# A function to do union of two subsets by rank
def union(parent, rank, x, y):
    x_root = find(parent, x)
    y_root = find(parent, y)

    # if both element in same sets
    if x_root == y_root:
        return

    # both elements not in the same sets, merge them
    # if rank of elements are different
    if rank[x_root] < rank[y_root]:
        # merge x_root into y_root
        parent[x_root] = y_root
    else:
        # merge y_root into x_root
        parent[y_root] = x_root

        # if both elements have equal rank
    if rank[x_root] == rank[y_root]:
        rank[x_root] += 1


# This class represents a undirected graph using adjacency list representation
class Graph:
    def __init__(self, vertices):
        self.V = vertices  # No. of vertices
        self.graph = defaultdict(list)  # default dictionary to store graph

    # function to add an edge to graph
    def add_edge(self, u, v):
        self.graph[u].append(v)

    # The main function to check whether a given graph
    # contains cycle or not
    def is_cyclic(self):

        # Allocate memory for creating V subsets and
        # Initialize all subsets as single element sets
        parent, rank = make_set(self.V)

        # Iterate through all edges of graph, find subset of both
        # vertices of every edge, if both subsets are same, then
        # there is cycle in graph.
        for _i in self.graph:
            for j in self.graph[_i]:
                x = find(parent, _i)
                y = find(parent, j)
                if x == y:
                    return True
                union(parent, rank, x, y)


if __name__ == "__main__":
    input_data = sys.stdin.read()
    data = list(map(int, input_data.split()))
    _vertices, edges = data[0:2]
    data = data[2:]
    g = Graph(_vertices)
    for i in range(edges):
        _u, _v = data[0:2]
        data = data[2:]
        g.add_edge(_u, _v)

    if g.is_cyclic():
        print("Graph contains cycle")
    else:
        print("Graph does not contain cycle")
