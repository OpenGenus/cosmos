""" 
This program reads the structure of the undirected graph for stdin, you can
feed it with a file using input/output redirections.

The structure of the input is :
number_of_nodes number_of_edges
u1 v1
u2 v2
...
"""


def dfs(u, p):
    global T

    V[u] = 1

    disc[u] = T
    low[u] = T
    T = T + 1

    # Used to count the number of children of a node
    count = 0

    for v in G[u]:
        if V[v] == 0:
            dfs(v, u)

            low[u] = min(low[u], low[v])
            count = count + 1

            if p != -1 and low[v] >= disc[u]:
                L.add(u)

        elif V[v] == 1 and v != p:
            low[u] = min(low[u], disc[v])

    V[u] = 2

    # This node is the root of the DFS tree, so it must be a cut vertex
    if p == -1 and count > 1:
        L.add(u)


# Read graph information from stdin
N, M = [int(s) for s in input().split(" ") if s != ""]

G = [list() for i in range(0, N)]
for i in range(0, M):
    u, v = [int(s) for s in input().split(" ") if s != ""]
    G[u].append(v)
    G[v].append(u)

# List of cut vertices
L = set()

# Array of visited nodes
# 0 : not visited
# 1 : currently visiting
# 2 : visited
V = [0] * N

T = 0
disc = [0] * N
low = [0] * N

# Go for DFS
for i in range(0, N):
    if V[i] == 0:
        dfs(i, -1)

print(L)
