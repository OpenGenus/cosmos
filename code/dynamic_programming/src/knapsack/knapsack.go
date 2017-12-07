// Part of Cosmos by OpenGenus Foundation
package main

import "fmt"

/*
Exptected output:

The value list is [12 34 1 23 5 8 19 10]
The weight list is [5 4 3 7 6 5 1 6]
For maxWeight 20, the max value is 89
*/

func max(n1, n2 int) int {
	if n1 > n2 {
		return n1
	}
	return n2
}

func knapsack(value, weight []int, maxWeight int) int {
	dp := make([][]int, len(value)+1)

	for i := range dp {
		dp[i] = make([]int, maxWeight+1)
		for j := range dp[i] {
			dp[i][j] = 0
		}
	}

	for i := 1; i <= len(value); i++ {
		for j := 1; j <= maxWeight; j++ {
			if weight[i-1] <= j {
				dp[i][j] = max(dp[i-1][j], value[i-1]+dp[i-1][j-weight[i-1]])
			} else {
				dp[i][j] = dp[i-1][j]
			}

		}
	}

	return dp[len(value)][maxWeight]
}

func main() {
	value := []int{12, 34, 1, 23, 5, 8, 19, 10}
	weight := []int{5, 4, 3, 7, 6, 5, 1, 6}
	maxWeight := 20
	fmt.Printf("The value list is %v\n", value)
	fmt.Printf("The weight list is %v\n", weight)
	fmt.Printf("For maxWeight %d, the max value is %d\n", maxWeight, knapsack(value, weight, maxWeight))
}
