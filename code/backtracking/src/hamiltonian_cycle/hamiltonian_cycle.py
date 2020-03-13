# Python program for the implementation of hamiltonian cycle problem 

class Graph(): 
	def __init__(self, vertices): 
		self.graph = [[0 for column in range(vertices)] 
							for row in range(vertices)] 
		self.V = vertices 

# Check if this vertex is an adjacent vertex of the previously added vertex and is not included in the path earlier 
	def isSafe(self, v, pos, path): 
		# Check if current vertex and last vertex in path are adjacent
		if self.graph[ path[pos-1] ][v] == 0: 
			return False

		# Check if current vertex not already in path 
		for vertex in path: 
			if vertex == v: 
				return False

		return True

	# A recursive utility function to solve the hamiltonian problem
	def hamCycleUtil(self, path, pos): 

		# base case: if all vertices are included in the path
		if pos == self.V: 
			# Last vertex must be adjacent to the 
			# first vertex in path to make a cyle 
			if self.graph[ path[pos-1] ][ path[0] ] == 1: 
				return True
			else: 
				return False

		for v in range(1,self.V): 

			if self.isSafe(v, pos, path) == True: 

				path[pos] = v 

				if self.hamCycleUtil(path, pos+1) == True: 
					return True

				# Remove current vertex if it doesn't leads to a solution 
				path[pos] = -1

		return False

	def hamCycle(self): 
		path = [-1] * self.V 
		path[0] = 0

		if self.hamCycleUtil(path,1) == False: 
			print ("Solution does not exist\n") 
			return False

		self.printSolution(path) 
		return True

	def printSolution(self, path): 
		print ("Solution Exists: Following", 
				"is one Hamiltonian Cycle") 
		for vertex in path: 
			print (vertex, end = " ") 
		print (path[0], "\n") 

# Driving code to test the function

g1 = Graph(5) 
g1.graph = [ [0, 1, 0, 1, 0], [1, 0, 1, 1, 1], 
			[0, 1, 0, 0, 1,],[1, 1, 0, 0, 1], 
			[0, 1, 1, 1, 0], ] 

g1.hamCycle(); 

g2 = Graph(5) 
g2.graph = [ [0, 1, 0, 1, 0], [1, 0, 1, 1, 1], 
		[0, 1, 0, 0, 1,], [1, 1, 0, 0, 0], 
		[0, 1, 1, 0, 0], ] 
 
g2.hamCycle(); 
