# Based in a code from http://www.geeksforgeeks.org/topological-sorting/
from collections import defaultdict

#Class to represent a graph
class Graph:
	def __init__(self,vertices):
		self.graph = defaultdict(list) #dictionary containing adjacency List
		self.V = vertices #No. of vertices

	# function to add an edge to graph
	def add_edge(self,u,v):
		self.graph[u].append(v)

	# A recursive function used by topological_sort
	def topological_sort_util(self,v,visited,stack):

		# Mark the current node as visited.
		visited[v] = True

		# Recur for all the vertices adjacent to this vertex
		for i in self.graph[v]:
			if not visited[i]:
				self.topological_sort_util(i,visited,stack)

		# Push current vertex to stack which stores result
		stack.insert(0,v)

	# The function to do Topological Sort. It uses recursive
	# topological_sort_util()
	def topological_sort(self):
		# Mark all the vertices as not visited
		visited = [False]*self.V
		stack =[]

		# Call the recursive helper function to store Topological
		# Sort starting from all vertices one by one
		for i in range(self.V):
			if not visited[i]:
				self.topological_sort_util(i,visited,stack)

		# Print contents of stack
		print stack
