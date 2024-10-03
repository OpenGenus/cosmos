
class Vertex:
    #initializes the vertex
    def __init__(self, id):
        self.id = id
        self.connectedTo = []

    #adds a connection to a vertex
    def addNeighbor(self, nbr):
        self.connectedTo.append(nbr)

    #print if the vertex is connected to a given vertex
    def ifConnected(self, nbr):
        return self.connectedTo[nbr]

    #print the connections of given vertex
    def printVertexConnections(self):
        allinfo = {'Vertex ID': self.id, 'Connections' : [i.id for i in self.connectedTo]}
        return allinfo

class Graph:
    #initializes the graph
    def __init__(self):
        self.vertList = {}
        self.numVertices = 0
        self.dfslist = []

    #adds vertex to graph
    def addVertex(self, key):
        self.numVertices += 1
        newVertex = Vertex(key)
        self.vertList[key] = newVertex

    #adds connection between two vertex
    def addEdge(self, f, t):
        if f not in self.vertList:
            self.addVertex(f)
        if t not in self.vertList:
            self.addVertex(t)

        self.vertList[f].addNeighbor(self.vertList[t])
        self.vertList[t].addNeighbor(self.vertList[f])

    #returns the entire graph
    def graphDetails(self):
        graphDict = {self.vertList[i].id :  [j.id for j in self.vertList[i].connectedTo] for i in self.vertList}
        return graphDict


#creates a graph with vertex A, B, C, D, E and corresponding connections
def assignSimpleGraph():
    g = Graph()
    g.addVertex('A')
    g.addVertex('B')
    g.addVertex('C')
    g.addVertex('D')
    g.addVertex('E')
    g.addEdge('A','B')
    g.addEdge('B','C')
    g.addEdge('B','D')
    g.addEdge('C','E')
    g.addEdge('D','E')
    return g

#prints the graph
def printGraph(g):
    details = g.graphDetails()
    print('The Graph')
    for i in details:
        print('{} : {}'.format(i, details[i]))


mygraph = assignSimpleGraph()
printGraph(mygraph)

#output =>
#The Graph
#A : ['B']
#B : ['A', 'C', 'D']
#C : ['B', 'E']
#D : ['B', 'E']
#E : ['C', 'D']
