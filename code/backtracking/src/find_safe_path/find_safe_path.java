// Java program to find shortest safe Route
// in the matrix with landmines
import java.util.Arrays;

class GFG{

static final int R = 12;
static final int C = 10;

// These arrays are used to get row and column
// numbers of 4 neighbours of a given cell
static int rowNum[] = { -1, 0, 0, 1 };
static int colNum[] = { 0, -1, 1, 0 };

static int min_dist;

// A function to check if a given cell (x, y)
// can be visited or not
static boolean isSafe(int[][] mat, boolean[][] visited,
					int x, int y)
{
	if (mat[x][y] == 0 || visited[x][y])
		return false;

	return true;
}

// A function to check if a given cell (x, y) is
// a valid cell or not
static boolean isValid(int x, int y)
{
	if (x < R && y < C && x >= 0 && y >= 0)
		return true;

	return false;
}

// A function to mark all adjacent cells of
// landmines as unsafe. Landmines are shown with
// number 0
static void markUnsafeCells(int[][] mat)
{
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			
			// If a landmines is found
			if (mat[i][j] == 0)
			{
				
				// Mark all adjacent cells
				for(int k = 0; k < 4; k++)
					if (isValid(i + rowNum[k], j + colNum[k]))
						mat[i + rowNum[k]][j + colNum[k]] = -1;
			}
		}
	}

	// Mark all found adjacent cells as unsafe
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if (mat[i][j] == -1)
				mat[i][j] = 0;
		}
	}

	// Uncomment below lines to print the path
	/*
	* for (int i = 0; i < R; i++) {
	* for (int j = 0; j < C; j++) { cout <<
	* std::setw(3) << mat[i][j]; } cout << endl; }
	*/
}

// Function to find shortest safe Route in the
// matrix with landmines
// mat[][] - binary input matrix with safe cells marked as 1
// visited[][] - store info about cells already visited in
// current route
// (i, j) are coordinates of the current cell
// min_dist --> stores minimum cost of shortest path so far
// dist --> stores current path cost
static void findShortestPathUtil(int[][] mat,
								boolean[][] visited,
								int i, int j, int dist)
{
	
	// If destination is reached
	if (j == C - 1)
	{
		
		// Update shortest path found so far
		min_dist = Math.min(dist, min_dist);
		return;
	}
	
	// If current path cost exceeds minimum so far
	if (dist > min_dist)
		return;

	// include (i, j) in current path
	visited[i][j] = true;

	// Recurse for all safe adjacent neighbours
	for(int k = 0; k < 4; k++)
	{
		if (isValid(i + rowNum[k], j + colNum[k]) &&
			isSafe(mat, visited, i + rowNum[k],
								j + colNum[k]))
		{
			findShortestPathUtil(mat, visited, i + rowNum[k],
							j + colNum[k], dist + 1);
		}
	}

	// Backtrack
	visited[i][j] = false;
}

// A wrapper function over findshortestPathUtil()
static void findShortestPath(int[][] mat)
{
	
	// Stores minimum cost of shortest path so far
	min_dist = Integer.MAX_VALUE;
	
	// Create a boolean matrix to store info about
	// cells already visited in current route
	boolean[][] visited = new boolean[R][C];

	// Mark adjacent cells of landmines as unsafe
	markUnsafeCells(mat);

	// Start from first column and take minimum
	for(int i = 0; i < R; i++)
	{
		
		// If path is safe from current cell
		if (mat[i][0] == 1)
		{
			
			// Initialize visited to false
			for(int k = 0; k < R; k++)
			{
				Arrays.fill(visited[k], false);
			}

			// Find shortest route from (i, 0) to any
			// cell of last column (x, C - 1) where
			// 0 <= x < R
			findShortestPathUtil(mat, visited, i, 0, 0);

			// If min distance is already found
			if (min_dist == C - 1)
				break;
		}
	}
	
	// If destination can be reached
	if (min_dist != Integer.MAX_VALUE)
		System.out.println("Length of shortest " +
						"safe route is " + min_dist);

	else
	
		// If the destination is not reachable
		System.out.println("Destination not " +
						"reachable from given source");
}

// Driver code
public static void main(String[] args)
{
	
	// Input matrix with landmines shown with number 0
	int[][] mat = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 } };

	// Find shortest path
	findShortestPath(mat);
}
}

// This code is contributed by sanjeev2552
