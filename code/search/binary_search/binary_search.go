package main

import "fmt"

//import "sort"

func binarySearch(data []int, value int) int {
	startIndex := 0
	endIndex := len(data) - 1

	for startIndex <= endIndex {
		midIndex := (startIndex + endIndex) / 2
		mid := data[midIndex]

		if mid < value {
			endIndex = midIndex - 1
		} else if mid > value {
			startIndex = midIndex + 1
		} else {
			return midIndex
		}

	}

	return -1

}

func main() {
	values := []int{1, 2, 3, 4, 5, 12, 35, 30, 46, 84}
	fmt.Println(binarySearch(values, 5))
	fmt.Println(binarySearch(values, 7))
}
