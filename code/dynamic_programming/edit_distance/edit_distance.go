/*
 * dynamic programming | edit distance | Go
 * Part of Cosmos by OpenGenus Foundation
 *
 * Compile: go build edit_distance.go
 */

package main

import (
	"fmt"
	"os"
)

func main() {

	if len(os.Args) != 3 {
		fmt.Println("Wrong input, write input next to the program call")
		fmt.Println("Example: ./edit_distance string1 string2")
		return
	}
	str1 := os.Args[1]
	str2 := os.Args[2]
	//str1 := "sunday"
	//str2 := "saturday"
	min := editDistance(str1, str2, len(str1), len(str2))
	fmt.Println(min)

}

func min(a, b int) int {
	if a < b {
		return a
	}

	return b
}

func editDistance(str1 string, str2 string, m int, n int) int {

	// Create table to store results of DP subproblems
	store := make([][]int, m+1)
	for i := range store {
		store[i] = make([]int, n+1)
	}
	for i := 0; i <= m; i++ {
		for j := 0; j <= n; j++ {
			if i == 0 {
				// When i is zero we must insert all (j) characters to get the second string
				store[i][j] = j
			} else if j == 0 {
				// Remove all characters in first string
				store[i][j] = i
			} else if str1[i-1] == str2[j-1] {
				// Last characters are equal, make recursion without last char
				store[i][j] = store[i-1][j-1]
			} else {
				// find minimum over all possibilities
				store[i][j] = 1 + min(min(store[i][j-1], store[i-1][j]), store[i-1][j-1])
			}
		}
	}
	return store[m][n]
}
