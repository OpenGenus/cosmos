package main

import (
	"fmt"
)

// Bead Sort in Golang
// Part of Cosmos by OpenGenus Foundation

// BeadSort sorts the given slice
func BeadSort(a []int) {
	n := len(a) // find the length of the array

	// this is used to handle for the edge case where there is nothing to sort
	if n == 0 {
		return
	}

	m := a[0]

	// get the max value of the array
	for _, value := range a {
		if value > m {
			m = value
		}
	}

	// create the grid of n rows and m columns and mark the beads
	grid := make([][]bool, n)
	for i, v := range a {
		grid[i] = make([]bool, m)
		for j := 0; j < v; j++ {
			grid[i][j] = true
		}
	}

	for j := 0; j < m; j++ {
		// count how many beads are on each post
		sum := 0
		for i := 0; i < n; i++ {
			if !grid[i][j] {
				continue
			}
			grid[i][j] = false
			sum++
		}

		// Move beads down
		for i := n - sum; i < n; i++ {
			grid[i][j] = true
		}
	}
	
	// Put sorted values in array using beads
	for i := 0; i < n; i++ {
		var j int
		for j = 0; j < m && grid[i][j]; j++ {

		}

		a[i] = j
	}
}

func main() {
	randomSlice := []int{5, 2, 8, 9, 10, 1, 3}
	fmt.Println("Unsorted Slice: ", randomSlice)
	BeadSort(randomSlice)
	// should receive [ 1, 2, 3, 5, 8, 9, 10 ]
	fmt.Println("Sorted Slice: ", randomSlice)
}
