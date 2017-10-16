/* Part of Cosmos by OpenGenus Foundation */
package main

import "fmt"

/*
Expteced output

The length of longest_increasing_subsequece in [10 23 5 81 36 37 12 38 51 92] is 7

*/

func max(n1, n2 int) int {
	if n1 > n2 {
		return n1
	}
	return n2
}

//O(n^2) approach
func LIS(data []int) int {
	dp := make([]int, len(data))

	ans := 0
	for i := range data {
		dp[i] = 1
		for j := 0; j < i; j++ {
			if data[j] < data[i] {
				dp[i] = max(dp[i], dp[j]+1)
			}
		}
		ans = max(ans, dp[i])

	}

	return ans
}

func main() {
	input := []int{10, 23, 5, 81, 36, 37, 12, 38, 51, 92}
	ans := LIS(input)
	fmt.Printf("The length of longest_increasing_subsequece in %v is %d\n", input, ans)
}
