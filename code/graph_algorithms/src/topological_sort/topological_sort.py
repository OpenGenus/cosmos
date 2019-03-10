""" Part of Cosmos by OpenGenus Foundation """

from collections import deque

NUM_V = 100005
adj_list = [[] for i in range(0, NUM_V)]
in_degree = [0 for i in range(0, NUM_V)]


def toposort():
    result = []
    q = deque()

    for i in range(1, vertex + 1):
        # if no incoming degree, add to queue
        if in_degree[i] == 0:
            q.append(i)

    while q:
        front = q.popleft()

        # add into toposort result
        result.append(front)

        for neighbor in adj_list[front]:
            in_degree[neighbor] -= 1

            # if already no incoming degree, then ready to put in toposort list
            if in_degree[neighbor] == 0:
                q.append(neighbor)

    return result


"""
consider following graph
1----->2----->5
|     ^^
|    / |
|   /  |
|  /   |
v /    |
4----->3
one of the solution would be
1 -> 4 -> 3 -> 2 -> 5
"""

vertex = 5
adj_list[1].append(2)
adj_list[1].append(4)
adj_list[2].append(5)
adj_list[3].append(2)
adj_list[4].append(2)
adj_list[4].append(3)

in_degree[1] = 0
in_degree[2] = 3
in_degree[3] = 1
in_degree[4] = 1
in_degree[5] = 1
result = toposort()

print("toposort :", end="")
for vtx in result:
    print(" {:d}".format(vtx), end="")

print()
