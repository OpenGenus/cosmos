import sys
from heap import Heap


def primsMSTAlgorithm(adjList):
    """
	Prim's Minimum Spanning Tree (MST) Algorithm 
	It finds a MST of an undirected graph
	Args:
		adjList: a dictionary, as a realization of an adjacency list, in the form
				 adjList[vertex1] = [(vertex21,weight1,edgeId1), (vertex22,weight2,edgeId2), ...]
				 Note: Every vertex should have an entry in the adjList
	Returns:
		mst: a set of all the edges (ids) that constitute the minimum spanning tree
	"""

    def updateHeap(v):
        """
		Updates the heap with entries of all the vertices incident to vertex v that was recently explored
		Args:
			v: a vertex that was recently explored
		"""
        for vertex, weight, edgeID in adjList[v]:
            if vertex not in explored:
                # Updates (!) the weight and reinserts the element into the heap
                element = unexplored.delete(vertex)
                if element and element[0] < weight:
                    unexplored.insert(element)
                else:
                    unexplored.insert((weight, vertex, edgeID))

    source = list(adjList.keys())[
        0
    ]  # Chooses an arbitrary vertex as the starting point of the algorithm
    # unexplored: a heap with elements of the following format (minWeight, destinationVertex, edgeID)
    unexplored, explored, mst = Heap(), set([source]), set()
    updateHeap(source)

    while unexplored.length():
        weight, vertex, edgeID = unexplored.extractMin()
        explored.add(vertex)
        mst.add(edgeID)
        updateHeap(vertex)

    return mst


def graph(filename):
    """
	Builds an adjacency list and an incidence list
	Args:
		filename: the name of the file with a representation of the graph. The first line of the file specifies
				  the number of the vertices and the number of the edges. The file is assumed to specify
				  the edges of the graph in the following format: v w e, where v is one vertex of the
				  associated edge, w is the other vertex, and e is the edge's weight
	
	Returns:
		adjList: a dictionary, as a realization of an adjacency list, in the form
				 adjList[vertex1] = [(vertex21,weight1,edgeId1), (vertex22,weight2,edgeId2), ...]
		edgeList: a dictionary, as a realization of an incidence list, in the form
				  edgeList[edgeId] = (vertex1,vertex2,weight)
	"""
    adjList, edgeList = {}, {}

    with open(filename, "r") as f:
        numbers = f.readline().split()
        numVertices, numEdges = int(numbers[0]), int(numbers[1])
        edgeID = 1

        for line in f:
            edge = line.split()
            vertex1, vertex2, weight = int(edge[0]), int(edge[1]), int(edge[2])

            if vertex1 in adjList:
                adjList[vertex1].append((vertex2, weight, edgeID))
            else:
                adjList[vertex1] = [(vertex2, weight, edgeID)]
            if vertex2 in adjList:
                adjList[vertex2].append((vertex1, weight, edgeID))
            else:
                adjList[vertex2] = [(vertex1, weight, edgeID)]

            edgeList[edgeID] = (vertex1, vertex2, weight)

            edgeID += 1

    return adjList, edgeList


if __name__ == "__main__":
    if len(sys.argv) < 2:
        sys.exit("Error: No filename")
    filename = sys.argv[1]

    adjList, edgeList = graph(filename)

    mst = primsMSTAlgorithm(adjList)

    cost = 0
    # Computes the sum of the weights of all edges in the MST
    for edgeID in mst:
        cost += edgeList[edgeID][2]
    print(cost)
