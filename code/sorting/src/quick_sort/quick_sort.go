// Quick Sort in Golang
// Part of Cosmos by OpenGenus Foundation
package main

import (
	"fmt"
	"math/rand"
)

// QuickSort sorts the given slice
func QuickSort(a []int) []int {

	if len(a) < 2 {
		return a
	}

	left, right := 0, len(a) - 1
	pivot := rand.Int() % len(a)

	a[pivot], a[right] = a[right], a[pivot]

	for i, _ := range a {
		if a[i] < a[right] {
			a[left], a[i] = a[i], a[left]
			left++
		}
	}

	a[left], a[right] = a[right], a[left]

	QuickSort(a[:left])
	QuickSort(a[left + 1:])

	return a
}

func main() {
	randomSlice := []int{ 1, 6, 2, 4, 9, 0, 5, 3, 7, 8 }
	fmt.Println("Unsorted Slice: ", randomSlice)
	QuickSort(randomSlice)
	fmt.Println("Sorted Slice: ", randomSlice)
}
