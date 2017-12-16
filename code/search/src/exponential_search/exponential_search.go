package main

import (
	"fmt"
)

func binarySearch(data []int, left int, right int, value int) int {
	if right >= left {
		mid := left + (right-left)/2
		if data[mid] == value {
			return mid
		}
		if data[mid] > value {
			return binarySearch(data, left, mid-1, value)
		}
		return binarySearch(data, mid+1, right, value)
	}

	return -1
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Part of Cosmos by OpenGenus Foundation
func exponentialSearch(data []int, n int, x int) int {
	if data[0] == x {
		return 0
	}

	i := 1
	for i < n && data[i] <= x {
		i = i * 2
	}

	return binarySearch(data, i/2, min(i, n), x)
}

func main() {
	values := []int{1, 2, 3, 4, 5, 12, 30, 35, 46, 84}
	fmt.Println(exponentialSearch(values, len(values)-1, 5))
	fmt.Println(exponentialSearch(values, len(values)-1, 35))
	fmt.Println(exponentialSearch(values, len(values)-1, 7))
}
