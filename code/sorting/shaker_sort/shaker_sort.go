// Part of Cosmos by OpenGenus Foundation
package main

import "fmt"

func shakerSort(sortMe []int) {
	beginningIdx := 0
	endIdx := len(sortMe) - 1
	for beginningIdx <= endIdx {
		newBeginningIdx := endIdx
		newEndIdx := beginningIdx
		swap := false
		for i := beginningIdx; i < endIdx; i++ {
			if sortMe[i] > sortMe[i+1] {
				sortMe[i], sortMe[i+1] = sortMe[i+1], sortMe[i]
				swap = true
				newEndIdx = i
			}
		}
		if !swap {
			break
		}
		endIdx = newEndIdx
		swap = false
		for i := endIdx; i >= beginningIdx; i-- {
			if sortMe[i] > sortMe[i+1] {
				sortMe[i], sortMe[i+1] = sortMe[i+1], sortMe[i]
				swap = true
				newBeginningIdx = i
			}
		}
		if !swap {
			break
		}
		beginningIdx = newBeginningIdx
	}
}

func main() {
	sortMe := [10]int{6, 4, 9, 5, 3, 10, 8, 1, 7, 2}
	fmt.Println(sortMe)
	shakerSort(sortMe[0:10])
	fmt.Println(sortMe)
}
