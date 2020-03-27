from collections import defaultdict 

class Graph: 
    def __init__(self,vertices): 
        self.graph = defaultdict(list) 
        self.V = vertices 
  
    
    def addEdge(self,u,v): 
        self.graph[u].append(v) 
  
    
    def topologicalSortUtil(self,v,visited,stack): 
  
        visited[v] = True
        for i in self.graph[v]: 
            if visited[i] == False: 
                self.topologicalSortUtil(i,visited,stack) 

        stack.insert(0,v) 

    def topologicalSort(self): 
       
        visited = [False]*self.V 
        stack =[] 
        for i in range(self.V): 
            if visited[i] == False: 
                self.topologicalSortUtil(i,visited,stack) 
  
        print(stack)
print("Enter the size of the directed graph")
n=int(input()) 
print("Enter the edges of the directed graph")
g= Graph(n) 
for i in range(0,n):
    val=str(input())
    arr=val.split(" ")
    edge1=int(arr[0])
    edge2=int(arr[1])
    g.addEdge(edge1,edge2)

print("Topological Sort of the given graph-:")
g.topologicalSort() 