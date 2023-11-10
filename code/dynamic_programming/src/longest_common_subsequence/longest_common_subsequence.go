/* Part of Cosmos by OpenGenus Foundation */
package main

import "fmt"

/*
Expect Output
The length of LCS of ABCDEFGHIJKLMNOPQRABCEDG adn DEFNMJABCDEG is 9

*/

func max(n1, n2 int) int {
	if n1 > n2 {
		return n1
	}
	return n2
}

func LCS(str1, str2 string) int {
	len1 := len(str1)
	len2 := len(str2)

	dp := make([][]int, len1+1)
	for v := range dp {
		dp[v] = make([]int, len2+1)
	}

	for i := 1; i <= len1; i++ {
		for j := 1; j <= len2; j++ {
			if str1[i-1] == str2[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
			} else {
				dp[i][j] = max(dp[i][j-1], dp[i-1][j])
			}
		}
	}

	return dp[len1][len2]
}

func main() {
	str1 := "ABCDEFGHIJKLMNOPQRABCEDG"
	str2 := "DEFNMJABCDEG"

	lcs := LCS(str1, str2)
	fmt.Printf("The length of LCS of %s adn %s is %d\n", str1, str2, lcs)
}
