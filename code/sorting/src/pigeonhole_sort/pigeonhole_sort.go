package main

import (
	"fmt"
)

// Pigeonhole Sort in Golang
// Part of Cosmos by OpenGenus Foundation

// PigeonholeSort sorts the given slice
func PigeonholeSort(a []int) {
	arrayLength := len(a)

	// this is used to handle for the edge case where there is nothing to sort
	if arrayLength == 0 {
		return
	}

	min := a[0]
	max := a[0]

	// get the min and max values of the array
	for _, value := range a {
		if value < min {
			min = value
		}

		if value > max {
			max = value
		}
	}

	size := max - min + 1

	// create the pigeon holes with the initial values
	holes := make(map[int][]int, size)
	for i := 0; i < size; i++ {
		holes[i] = []int{}
	}

	// for every value in the array, put it in the corresponding pigeonhole
	for _, value := range a {
		holes[value-min] = append(holes[value-min], value)
	}

	// finally, replace the values in the array with the values from each
	// pigeonhole in order
	j := 0
	for i := 0; i < size; i++ {
		for _, value := range holes[i] {
			a[j] = value
			j++
		}
	}
}

func main() {
	randomSlice := []int{5, 2, 8, 9, 10, 1, 3}
	fmt.Println("Unsorted Slice: ", randomSlice)
	PigeonholeSort(randomSlice)
	// should receive [ 1, 2, 3, 5, 8, 9, 10 ]
	fmt.Println("Sorted Slice: ", randomSlice)
}
