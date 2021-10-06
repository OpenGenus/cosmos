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
