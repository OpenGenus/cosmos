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

//O(n*logn) approach
func LISV2(data []int) int {
	tail := make([]int, 0)

	var find int
	for i := range data {

		find = -1
		//lower bound, we search from back to head
		for v := range tail {
			if tail[len(tail)-v-1] > data[i] {
				find = len(tail) - 1 - v
			}
		}
		if find == -1 {
			tail = append(tail, data[i])
		} else {
			tail[find] = data[i]
		}
	}
	return len(tail)
}

func main() {
	input := []int{10, 23, 5, 81, 36, 37, 12, 38, 51, 92}
	ans := LIS(input)
	fmt.Printf("The length of longest_increasing_subsequece in %v is %d\n", input, ans)
	ans = LISV2(input)
	fmt.Printf("The length of longest_increasing_subsequece in %v is %d\n", input, ans)
}
