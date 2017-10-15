package main

import (
	"fmt"
)

// Part of Cosmos by OpenGenus Foundation
func main() {
	arr := []int{1, 6, 4, 7, 2, 8}
	fmt.Printf("Before sort: %v\n", arr)
	CycleSort(&arr)
	fmt.Printf("After sort: %v\n", arr)
}

func CycleSort(arr *[]int) int {
	writes := 0

	// Loop through the array to find cycles to rotate.
	for cycleStart, item := range *arr {

		// Find where to put the item.
		pos := cycleStart
		for i := cycleStart + 1; i < len(*arr); i++ {
			if (*arr)[i] < item {
				pos++
			}
		}

		// If the item is already there, this is not a cycle.
		if pos != cycleStart {

			// Put the item there or right after any duplicates.
			for item == (*arr)[pos] {
				pos++
			}
			(*arr)[pos], item = item, (*arr)[pos]
			writes++

			// Rotate the rest of the cycle
			for pos != cycleStart {
				// Find where to put the item
				pos = cycleStart
				for i := cycleStart + 1; i < len(*arr); i++ {
					if (*arr)[i] < item {
						pos++
					}
				}

				// Put the item there or right after any duplicates.
				for item == (*arr)[pos] {
					pos++
				}
				(*arr)[pos], item = item, (*arr)[pos]
				writes++
			}
		}
	}

	return writes
}
