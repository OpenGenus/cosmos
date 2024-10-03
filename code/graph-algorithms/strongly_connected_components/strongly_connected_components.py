# Part of Cosmos by OpenGenus Foundation

from collections import defaultdict
result = defaultdict(list)
import operator

Art = []
time = 0
path  = []
scc = []
flag = 0

class Graph:

    def __init__(self):
        self.graph = defaultdict(list)
        self.graphT = defaultdict(list)
 
    def addEdge(self,u,v):
        self.graph[u].append(v)
        self.graphT[v].append(u)
 
    def DFS_trav(self,u):
        global time
        time = time +1
        discovered[u] = time
        color[u] = "G"
        path.append(u)
        
        for v in self.graph[u]:
            if color[v] == "W":
                self.DFS_trav(v)
                
        color[u] = "B"
        time += 1
        finish[u] = time
 
    def DFS(self,source):
        for u in self.graph:
            color[u] = "W"
        self.DFS_trav(source)
        for u in self.graph:
            if color[u] == "W":
                self.DFS_trav(u)
    
    
    def finish_dict(self):
        fin_dict = {}
        for i in range(len(finish)):
            fin_dict[i] = finish[i]
        fin_dict_sor = sorted(fin_dict.items(), key=operator.itemgetter(1),reverse = True)
        return fin_dict_sor

    def SCC(self,fin):
        self.graph = self.graphT
        global path
        path = []

        for ver, val in fin:
            color[ver] = "W"
        
        for ver, val in fin[:len(fin)-1]:
            if color[ver] == "W":
                self.DFS_trav(ver)
                print("======")
                print(path)
                path = []
                
    
g = Graph()
g.addEdge(1,2)
g.addEdge(2,3)
g.addEdge(3,4)
g.addEdge(4,3)
g.addEdge(2,5)
g.addEdge(2,6)
g.addEdge(5,6)
g.addEdge(6,7)
g.addEdge(7,6)
g.addEdge(7,8)
g.addEdge(8,8)
g.addEdge(3,7)
g.addEdge(4,8)
g.addEdge(5,1)

size = len(g.graph) + 1

discovered = [float("inf")]*size
finish = [0]*size
color = [0] * size
source = 3
g.DFS(source)


fin_dict_sor = g.finish_dict()
print("SCC are: ")
g.SCC(fin_dict_sor)


