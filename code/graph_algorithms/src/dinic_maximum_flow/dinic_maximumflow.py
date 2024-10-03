#Dinic's Algorithm

#Explanation:-
# Initialize residual graph G as given graph.
# Do BFS of G to construct a level graph (or assign levels to vertices) and also check if more flow is possible



class Edge:
    def __init__(self, v, flow, C, rev):
        self.v = v
        self.flow = flow
        self.C = C
        self.rev = rev
 
# Residual Graph
 
 
class Graph:
    def __init__(self, V):
        self.adj = [[] for i in range(V)]
        self.V = V
        self.level = [0 for i in range(V)]
 
    # add edge to the graph
    def addEdge(self, u, v, C):
 
        # Forward edge : 0 flow and C capacity
        a = Edge(v, 0, C, len(self.adj[v]))
 
        # Back edge : 0 flow and 0 capacity
        b = Edge(u, 0, 0, len(self.adj[u]))
        self.adj[u].append(a)
        self.adj[v].append(b)
 
    # Finds if more flow can be sent from s to t
    # Also assigns levels to nodes
    def BFS(self, s, t):
        for i in range(self.V):
            self.level[i] = -1
 
        # Level of source vertex
        self.level[s] = 0
 
        # Create a queue, enqueue source vertex
        # and mark source vertex as visited here
        # level[] array works as visited array also
        q = []
        q.append(s)
        while q:
            u = q.pop(0)
            for i in range(len(self.adj[u])):
                e = self.adj[u][i]
                if self.level[e.v] < 0 and e.flow < e.C:
 
                    # Level of current vertex is
                    # level of parent + 1
                    self.level[e.v] = self.level[u]+1
                    q.append(e.v)
 
        # If we can not reach to the sink we
        # return False else True
        return False if self.level[t] < 0 else True
 
# A DFS based function to send flow after BFS has
# figured out that there is a possible flow and
# constructed levels. This functions called multiple
# times for a single call of BFS.
# flow : Current flow send by parent function call
# start[] : To keep track of next edge to be explored
#           start[i] stores count of edges explored
#           from i
# u : Current vertex
# t : Sink
    def sendFlow(self, u, flow, t, start):
        # Sink reached
        if u == t:
            return flow
 
        # Traverse all adjacent edges one -by -one
        while start[u] < len(self.adj[u]):
 
            # Pick next edge from adjacency list of u
            e = self.adj[u][start[u]]
            if self.level[e.v] == self.level[u]+1 and e.flow < e.C:
 
                # find minimum flow from u to t
                curr_flow = min(flow, e.C-e.flow)
                temp_flow = self.sendFlow(e.v, curr_flow, t, start)
 
                # flow is greater than zero
                if temp_flow and temp_flow > 0:
 
                    # add flow to current edge
                    e.flow += temp_flow
 
                    # subtract flow from reverse edge
                    # of current edge
                    self.adj[e.v][e.rev].flow -= temp_flow
                    return temp_flow
            start[u] += 1
 
    # Returns maximum flow in graph
    def DinicMaxflow(self, s, t):
 
        # Corner case
        if s == t:
            return -1
 
        # Initialize result
        total = 0
 
        # Augument the flow while there is path
        # from source to sink
        while self.BFS(s, t) == True:
 
            # store how many edges are visited
            # from V { 0 to V }
            start = [0 for i in range(self.V+1)]
            while True:
                flow = self.sendFlow(s, float('inf'), t, start)
                if not flow:
                    break
 
                # Add path flow to overall flow
                total += flow
 
        # return maximum flow
        return total
 
# A Graph for Illustrating the maximum flow using dinic algorithm
g = Graph(6)
g.addEdge(0, 1, 16)
g.addEdge(0, 2, 13)
g.addEdge(1, 2, 10)
g.addEdge(1, 3, 12)
g.addEdge(2, 1, 4)
g.addEdge(2, 4, 14)
g.addEdge(3, 2, 9)
g.addEdge(3, 5, 20)
g.addEdge(4, 3, 7)
g.addEdge(4, 5, 4)
print("Maximum flow", g.DinicMaxflow(0, 5))


#Time Complexity - O(EV^2)
#space Complexity - O(E+V)

