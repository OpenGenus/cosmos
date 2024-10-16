from collections import defaultdict


class Graph:
    def __init__(self, V, directed=False):
        self.V = V
        self.directed = directed
        self.graph = defaultdict(list)

    def add_edge(self, a, b):
        self.graph[a].append(b)

        if not self.directed:
            self.graph[b].append(a)

    def color_greedy(self):
        result = [-1] * self.V
        max_color = 0
        for v, adj in self.graph.items():
            color = 0
            while color in [result[x] for x in adj]:
                color += 1
            max_color = max(max_color, color)
            result[v] = color
        return result, max_color


if __name__ == "__main__":

    g = Graph(5)

    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 2)
    g.add_edge(1, 3)
    g.add_edge(2, 3)
    g.add_edge(3, 4)

    res, m = g.color_greedy()

    print("max colors: {} list: {}".format(m, res))
