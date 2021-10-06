class graph:
    adj=[]
    def __init__(self,v,e):
        self.v=v
        self.e=e
        graph.adj=[[0 for i in range(v)] for i in range(v)]
        
    def adj_matrix(self,start,e):
        graph.adj[start][e]=1
        graph.adj[e][start]=1
        
    def display_adj_matrix(self):
        print("The adjacency matrix is: \n")
        for i in range (v):
            for j in range (v):
                print(graph.adj[i][j], end =" ")
            print("\n")
choice="y"
v=int(input("Enter number of vertices: "))
e=v
g = graph(v,e)
print("The vertices are: ")
for i in range (v):
    print(i, end=' ')
print('\n')
while choice == 'y':
    x = int(input("Enter vertex 1: "))
    y = int(input("Enter vertex 2: "))
    g.adj_matrix(x,y)
    choice = input("Do you want to add more edges? (y/n): ")
    if choice == "n":
        break
g.display_adj_matrix()
"""
Output:
Enter number of vertices: 3
The vertices are: 
0 1 2 

Enter vertex 1: 1
Enter vertex 2: 2
Do you want to add more edges? (y/n): y
Enter vertex 1: 0
Enter vertex 2: 2
Do you want to add more edges? (y/n): n
The adjacency matrix is: 

0 0 1 

0 0 1 

1 1 0 
"""
