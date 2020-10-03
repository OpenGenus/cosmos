package main

import (
	"fmt"
)

// Gnome Sort in Golang
// Part of Cosmos by OpenGenus Foundation

// GnomeSort sorts the given slice
func GnomeSort(a []int) {
	pos := 0
	for pos < len(a) {
		if pos == 0 || a[pos] >= a[pos-1] {
			pos++
		} else {
			a[pos], a[pos-1] = swap(a[pos], a[pos-1])
			pos--
		}
	}
}

func swap(x int, y int) (int, int) {
	return y, x
}

func main() {
	randomSlice := []int{5, 2, 8, 9, 10, 1, 3}
	fmt.Println("Unsorted Slice: ", randomSlice)
	GnomeSort(randomSlice)
	// should receive [ 1, 2, 3, 5, 8, 9, 10 ]
	fmt.Println("Sorted Slice: ", randomSlice)
}
