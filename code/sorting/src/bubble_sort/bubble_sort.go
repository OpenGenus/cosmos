package main

import (
	"fmt"
)

func bubbleSort(tosort []int) {
	size := len(tosort)
	if size < 2 {
		return
	}
	for i := 0; i < size; i++ {
		for j := size - 1; j >= i+1; j-- {
			if tosort[j] < tosort[j-1] {
				tosort[j], tosort[j-1] = tosort[j-1], tosort[j]
			}
		}
	}
}

func main() {
	unsorted := []int{1, 199, 3, 2, 5, 80, 99, 500}
	
	fmt.Println("Before : ", unsorted)
	
	bubbleSort(unsorted)
	
	fmt.Println("After : ", unsorted)
}