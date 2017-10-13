package main

// Selection Sort in Golang
// Part of Cosmos by OpenGenus Foundation
import "fmt"

func selectionSort(array [8]int) [8]int {
	for i := 0; i < len(array); i++ {
		min := i
		for j := i + 1; j < len(array); j++ {
			if array[j] < array[min] {
				min = j
			}
		}
		array[i], array[min] = array[min], array[i]
	}
	return array
}

func main() {
	array := [8]int{5, 6, 1, 2, 7, 9, 8, 4}
	sorted := selectionSort(array)
	fmt.Printf("%v\n", sorted)
}
