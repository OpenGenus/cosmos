# Python3 program to find shortest safe Route
# in the matrix with landmines
import sys

R = 12
C = 10

# These arrays are used to get row and column
# numbers of 4 neighbours of a given cell
rowNum = [ -1, 0, 0, 1 ]
colNum = [ 0, -1, 1, 0 ]

min_dist = sys.maxsize

# A function to check if a given cell (x, y)
# can be visited or not
def isSafe(mat, visited, x, y):

	if (mat[x][y] == 0 or visited[x][y]):
		return False

	return True

# A function to check if a given cell (x, y) is
# a valid cell or not
def isValid(x, y):

	if (x < R and y < C and x >= 0 and y >= 0):
		return True

	return False

# A function to mark all adjacent cells of
# landmines as unsafe. Landmines are shown with
# number 0
def markUnsafeCells(mat):

	for i in range(R):
		for j in range(C):
			# If a landmines is found
			if (mat[i][j] == 0):
				# Mark all adjacent cells
				for k in range(4):
					if (isValid(i + rowNum[k], j + colNum[k])):
						mat[i + rowNum[k]][j + colNum[k]] = -1

	# Mark all found adjacent cells as unsafe
	for i in range(R):
		for j in range(C):
			if (mat[i][j] == -1):
				mat[i][j] = 0

	""" Uncomment below lines to print the path
	/*
	* for (int i = 0; i < R; i++) {
	* for (int j = 0; j < C; j++) { cout <<
	* std::setw(3) << mat[i][j]; } cout << endl; }
	*"""

# Function to find shortest safe Route in the
# matrix with landmines
# mat[][] - binary input matrix with safe cells marked as 1
# visited[][] - store info about cells already visited in
# current route
# (i, j) are coordinates of the current cell
# min_dist --> stores minimum cost of shortest path so far
# dist --> stores current path cost
def findShortestPathUtil(mat, visited, i, j, dist):
	
	global min_dist

	# If destination is reached
	if (j == C - 1):
		# Update shortest path found so far
		min_dist = min(dist, min_dist)
		return

	# If current path cost exceeds minimum so far
	if (dist > min_dist):
		return

	# include (i, j) in current path
	visited[i][j] = True

	# Recurse for all safe adjacent neighbours
	for k in range(4):
		if (isValid(i + rowNum[k], j + colNum[k]) and isSafe(mat, visited, i + rowNum[k], j + colNum[k])):
			findShortestPathUtil(mat, visited, i + rowNum[k], j + colNum[k], dist + 1)

	# Backtrack
	visited[i][j] = False

# A wrapper function over findshortestPathUtil()
def findShortestPath(mat):
	
	global min_dist

	# Stores minimum cost of shortest path so far
	min_dist = sys.maxsize

	# Create a boolean matrix to store info about
	# cells already visited in current route
	visited = [[False for i in range(C)] for j in range(R)]

	# Mark adjacent cells of landmines as unsafe
	markUnsafeCells(mat)

	# Start from first column and take minimum
	for i in range(R):
		# If path is safe from current cell
		if (mat[i][0] == 1):
			# Find shortest route from (i, 0) to any
			# cell of last column (x, C - 1) where
			# 0 <= x < R
			findShortestPathUtil(mat, visited, i, 0, 0)

			# If min distance is already found
			if (min_dist == C - 1):
				break

	# If destination can be reached
	if (min_dist != sys.maxsize):
		print("Length of shortest safe route is", min_dist)
	else:
		# If the destination is not reachable
		print("Destination not reachable from given source")
		
mat = [
		[ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ],
		[ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 ],
		[ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 ],
		[ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 ],
		[ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ],
		[ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 ],
		[ 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 ],
		[ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ],
		[ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ],
		[ 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 ],
		[ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ],
		[ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 ] ]

# Find shortest path
findShortestPath(mat)

# This code is contributed by mukesh07.
