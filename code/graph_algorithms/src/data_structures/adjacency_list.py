class graph:
            def __init__(self):
                        self.graph={}
            def graph_input(self,n):
                        for i in range(1,n+1):

                                    self.graph.update({i:None})
                                    element=[ ]
                                    choice='y'
                                    while choice=='y':
                                                x=int(input("Enter the edge for vertex %d: "%i))
                                                element.append(x)
                                                self.graph[i]=element
                                                choice=input("Do you want to add more edges? (y/n):")
                        print("The adjacency list is:")
                        print(self.graph)

                
n=int(input("enter total number of nodes: "))
g=graph()
g.graph_input(n)
"""
Output:
enter total number of nodes: 3
Enter the edge for vertex 1: 2
Do you want to add more edges? (y/n):y
Enter the edge for vertex 1: 3
Do you want to add more edges? (y/n):n
Enter the edge for vertex 2: 1
Do you want to add more edges? (y/n):y
Enter the edge for vertex 2: 3
Do you want to add more edges? (y/n):n
Enter the edge for vertex 3: 1
Do you want to add more edges? (y/n):y
Enter the edge for vertex 3: 2
Do you want to add more edges? (y/n):n
The adjacency list is:
{1: [2, 3], 2: [1, 3], 3: [1, 2]}
"""
