from collections import defaultdict


class Graph:
    def __init__(self, v):
        self.v = v
        self.adj = defaultdict(list)

    def add_edge(self, u, v):
        self.adj[u].append(v)

    def find_parent(self, v, set_map):
        return v if set_map[v] == -1 else self.find_parent(set_map[v], set_map)

    def union(self, u, v, set_map):
        x = self.find_parent(u, set_map)
        y = self.find_parent(v, set_map)
        set_map[x] = y

    def is_cyclic(self):
        set_map = [-1] * self.v
        visited = [False] * self.v

        for u, vs in self.adj.items():
            # assume there's only one edge
            for v in vs:
                x = self.find_parent(u, set_map)
                y = self.find_parent(v, set_map)
                if x == y:
                    return True
                self.union(x, y, set_map)

        # print(set_map)
        return False


if __name__ == "__main__":
    g = Graph(4)
    g.add_edge(0, 1)
    g.add_edge(1, 2)
    g.add_edge(2, 3)

    print(g.is_cyclic())
    g.add_edge(3, 0)
    print(g.is_cyclic())

    g = Graph(4)
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 2)
    g.add_edge(2, 0)
    g.add_edge(2, 3)
    g.add_edge(3, 3)

    print(g.is_cyclic())
