package main

import (
	"fmt"
)

// Part of Cosmos by OpenGenus Foundation

func main() {
	array := []int{9, 6, 7, 3, 2, 4, 5, 1}
	insertion(array)
}

func insertion(array []int) {
	lenght := len(array)

	for i := 1; i < lenght; i++ {
		j := i

		for j > 0 && array[j-1] > array[j] {
			array[j-1], array[j] = array[j], array[j-1]

			j = j - 1
		}
	}

	fmt.Println(array)
}
