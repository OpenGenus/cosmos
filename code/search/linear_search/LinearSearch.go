package main

import (
	"fmt"
)

func main() {
	arr := []int{1, 3, 45, 56, 8, 21, 7, 69, 12}
	find := 56
	index := search(arr, find)
	if index != -1 {
		fmt.Printf("%d found at index %d", find, index)
	} else {
		fmt.Printf("%d not found!", find)
	}

}

func search(arr []int, x int) int {
	for i, n := range arr {
		if n == x {
			return i
		}
	}
	return -1
}
