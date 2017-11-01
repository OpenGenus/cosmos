from collections import defaultdict

class Graph:

    def __init__(self, v):
        self.v = v
        self.adj = defaultdict(list)

    def addEdge(self, u, v):
        self.adj[u].append(v)

    def findParent(self, v, setMap):
        if setMap[v] == -1:
            return v
        else:
            return self.findParent(setMap[v], setMap)

    def union(self, u, v, setMap):
        x = self.findParent(u, setMap)
        y = self.findParent(v, setMap)
        setMap[x] = y
    
    def hasCycle(self):
        setMap = [-1] * self.v
        visited = [False] * self.v

        for u, vs in self.adj.items():
            # assume there's only one edge
            for v in vs:
                x = self.findParent(u, setMap)
                y = self.findParent(v, setMap)
                if x == y:
                    return True
                self.union(x, y, setMap)

            
        # print(setMap)
        return False


    
if __name__ == '__main__':
    g = Graph(4)
    g.addEdge(0, 1)
    g.addEdge(1, 2)
    g.addEdge(2, 3)

    print(g.hasCycle())
    g.addEdge(3, 0)
    print(g.hasCycle())

    g = Graph(4)
    g.addEdge(0, 1)
    g.addEdge(0, 2)
    g.addEdge(1, 2)
    g.addEdge(2, 0)
    g.addEdge(2, 3)
    g.addEdge(3, 3)

    print(g.hasCycle())
