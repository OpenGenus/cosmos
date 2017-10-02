// Selection Sort in Golang
// Part of Cosmos by OpenGenus Foundation
package main

import (
	"fmt"
)

// SelectionSort sorts the given slice
func SelectionSort(items []int) {
	var n = len(items)
	for i := 0; i < n; i++ {
		var minIdx = i
		for j := i; j < n; j++ {
			if items[j] < items[minIdx] {
				minIdx = j
			}
		}
		items[i], items[minIdx] = items[minIdx], items[i]
	}
}

func main() {
	randomSlice := []int{1, 6, 2, 4, 9, 0, 5, 3, 7, 8}
	fmt.Println("Unsorted Slice: ", randomSlice)
	SelectionSort(randomSlice)
	fmt.Println("Sorted Slice: ", randomSlice)
}
