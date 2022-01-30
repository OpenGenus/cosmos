""" Part of Cosmos by OpenGenus Foundation """

INF = 1000000000


def floyd_warshall(vertex, adjacency_matrix):

    # calculating all pair shortest path
    for k in range(0, vertex):
        for i in range(0, vertex):
            for j in range(0, vertex):

                # relax the distance from i to j by allowing vertex k as intermediate vertex
                # consider which one is better, going through vertex k or the previous value
                adjacency_matrix[i][j] = min(
                    adjacency_matrix[i][j],
                    adjacency_matrix[i][k] + adjacency_matrix[k][j],
                )

                # pretty print the graph
                # o/d means the leftmost row is the origin vertex
                # and the topmost column as destination vertex
    print("o/d", end="")
    for i in range(0, vertex):
        print("\t{:d}".format(i + 1), end="")
    print()

    for i in range(0, vertex):
        print("{:d}".format(i + 1), end="")

        for j in range(0, vertex):
            print("\t{:d}".format(adjacency_matrix[i][j]), end="")

        print()


"""
input is given as adjacency matrix,
input represents this undirected graph

 A--1--B
 |    /
 3   /
 |  1
 | /
 C--2--D

should set infinite value for each pair of vertex that has no edge
 """

adjacency_matrix = [[0, 1, 3, INF], [1, 0, 1, INF], [3, 1, 0, 2], [INF, INF, 2, 0]]
floyd_warshall(4, adjacency_matrix)
