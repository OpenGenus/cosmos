// Part of Cosmos by OpenGenus Foundation

// Given a cost matrix and calculate the minimum cost path to reach (m, n) 
// from (0, 0)

import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

class MinCostPath {
	static int minCost(int costMatrix[][], int m, int n) {
		int i,j;
		int tc[][] = new int[m+1][n+1];
		
		tc[0][0] = costMatrix[0][0];
		
		for (i = 1; i <= m; i++)
			tc[i][0] = tc[i-1][0] + costMatrix[i][0];
 
		for (j = 1; j <= n; j++)
			tc[0][j] = tc[0][j-1] + costMatrix[0][j];

		for (i = 1; i <= m; i++)
			for (j = 1; j <= n; j++)
				tc[i][j] = min(tc[i-1][j-1], 
				tc[i-1][j], 
				tc[i][j-1]) + costMatrix[i][j];
		
		return tc[m][n];
	}
	
	static int min(int x, int y, int z) {
		if (x < y)
			return (x < z)? x : z;
		else
			return (y < z)? y : z;
	}
	
	public static void main(String args[]) {
		int cost[][] = 	new int[][]{ 
					{1, 2, 3},
					{4, 8, 2},
					{1, 5, 3} 
					};
		System.out.println(minCost(cost, 2, 2));
	}
}
