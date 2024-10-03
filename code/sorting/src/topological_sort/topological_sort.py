from collections import defaultdict 

class Graph: 
    def __init__(self,vertices): 
        self.graph = defaultdict(list) 
        self.V = vertices 
  
    
    def __addEdge__(self,u,v): 
        self.graph[u].append(v) 
  
    
    def __topologicalSortUtil__(self,v,visited,stack): 
  
        visited[v] = True
        for i in self.graph[v]: 
            if visited[i] == False: 
                self.__topologicalSortUtil__(i,visited,stack) 

        stack.insert(0,v) 

    def __topologicalSort__(self): 
       
        visited = [False]*self.V 
        stack =[] 
        for i in range(self.V): 
            if visited[i] == False: 
                self.__topologicalSortUtil__(i,visited,stack) 
  
        print(stack)
print("Enter the size of the directed graph")
n=int(input()) 
print("Enter the edges of the directed graph")
g= Graph(n) 
for i in range(0,n):
    val=str(input())
    arr=val.split(" ")
    edge1, edge2 = map(int, val.split(" "))
    g.__addEdge__(edge1,edge2)

print("Topological Sort of the given graph-:")
g.__topologicalSort__() 