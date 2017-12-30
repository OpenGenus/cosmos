/*
 * dynamic programming | coin change | Go
 * Part of Cosmos by OpenGenus Foundation
 */
package main

import "fmt"

/*
There are 22 ways to combine 8 from [1 2 3 4 5 6 7 8 9 10]
*/

//DP[i] += DP[i-coint[i]]
//j = coinset,
//i = for each money
func solveCoinChange(coins []int, target int) int {

	dp := make([]int, target+1)
	dp[0] = 1 //basic

	for _, v := range coins {
		for i := 1; i <= target; i++ {
			if i >= v {
				dp[i] += dp[i-v]
			}
		}
	}

	return dp[target]
}
func main() {
	coins := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	target := 8

	way := solveCoinChange(coins, target)
	fmt.Printf("There are %d ways to combine %d from %v\n", way, target, coins)
}
