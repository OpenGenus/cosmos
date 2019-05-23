#python3
# Python Program for union-find algorithm to detect cycle in a undirected graph

import sys
from collections import defaultdict


# this function initializes all single element sets
def makeset(n):
    parent = [None] * n
    rank = [None] * n
    for i in range(n):
        parent[i] = i
        rank[i] = 0
    return parent, rank


# A function to find the ID of an element i 
def find(parent, i): 
	if parent[i] != i:
	# path compression
	    parent[i] = find(parent, parent[i])
	return parent[i]


# A function to do union of two subsets by rank
def union(parent, rank, x, y): 
	xRoot = find(parent, x)
	yRoot = find(parent, y)
		
	# if both element in same sets
	if xRoot == yRoot:
	    return
		
	# both elements not in the same sets, merge them
	# if rank of elements are different
	if rank[xRoot] < rank[yRoot]:
	    # merge xRoot into yRoot
	    parent[xRoot] = yRoot
	else:
	    # merge yRoot into xRoot
	    parent[yRoot] = xRoot
		    
        # if both elements have equal rank
        if rank[xRoot] == rank[yRoot]:
            rank[xRoot] += 1


#This class represents a undirected graph using adjacency list representation 
class Graph: 

	def __init__(self,vertices): 
		self.V= vertices #No. of vertices 
		self.graph = defaultdict(list) # default dictionary to store graph 


	# function to add an edge to graph 
	def addEdge(self,u,v): 
		self.graph[u].append(v) 
    

	# The main function to check whether a given graph 
	# contains cycle or not 
	def isCyclic(self): 
		
		# Allocate memory for creating V subsets and 
		# Initialize all subsets as single element sets 
		parent, rank = makeset(self.V)

		# Iterate through all edges of graph, find subset of both 
		# vertices of every edge, if both subsets are same, then 
		# there is cycle in graph. 
		for i in self.graph: 
			for j in self.graph[i]: 
				x = find(parent, i) 
				y = find(parent, j) 
				if x == y: 
					return True
				union(parent, rank, x ,y) 


input = sys.stdin.read()
data = list(map(int, input.split()))
vertices, edges = data[0:2]
data = data[2:]
g = Graph(vertices)
for i in range(edges):
    u,v = data[0:2]
    data = data[2:]
    g.addEdge(u, v)

if g.isCyclic(): 
	print "Graph contains cycle"
else : 
	print "Graph does not contain cycle "
