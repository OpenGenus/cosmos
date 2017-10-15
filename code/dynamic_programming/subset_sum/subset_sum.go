/* Part of Cosmos by OpenGenus Foundation */
package main

import "fmt"

const TargetSize int = 200

/*
Expected Output:
Current subset is [1 4 8 9 34 23 17 32]
We can't get sum 113 from set
We can get sum 9 from set
We can't get sum 15 from set
We can't get sum 20 from set
We can get sum 31 from set
*/
func subSetSum(subset []int, dp [][]int) {
	for i := range dp {
		dp[i] = make([]int, TargetSize+1)
		for j := range dp[i] {
			dp[i][j] = 0
		}

		//If sum is 0, then it's true
		dp[i][0] = 1
	}

	for i := 1; i <= len(subset); i++ {
		for j := 0; j < TargetSize; j++ {
			dp[i][j] = dp[i-1][j]
			if j >= subset[i-1] {
				dp[i][j] += dp[i-1][j-subset[i-1]]
			}
		}

	}
}

func main() {
	input := []int{1, 4, 8, 9, 34, 23, 17, 32}

	// The value of dp[i][j] will be true if there is a
	// dp of set[0..i-1] with sum equal to j
	dp := make([][]int, len(input)+1)
	subSetSum(input, dp)

	sum := []int{113, 9, 15, 20, 31}
	fmt.Printf("Current subset is %v\n", input)
	for _, v := range sum {
		if dp[len(input)][v] == 0 {
			fmt.Printf("We can't get sum %d from set\n", v)
		} else {
			fmt.Printf("We can get sum %d from set\n", v)
		}
	}
}
