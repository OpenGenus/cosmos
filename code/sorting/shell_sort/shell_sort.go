package main

import (
    "fmt"
)

func main() {
    var n int
    fmt.Println("Please enter the lenght of the array:")
    fmt.Scan(&n)
    X := make([]int, n)

    fmt.Println("Now, enter the elements X0 X1 ... Xn-1")

     for i := 0; i < n; i++ {
        fmt.Scanln(&X[i])
    }

    fmt.Printf("Unsorted array: %v\n", X)
    fmt.Printf("Sorted array: %v\n", BubbleSort(X))
    
}

func shellSort(array []int) {
	h := 1
	for h < len(array) {
		h = 3 * h + 1
	}
	for h >= 1 {
		for i := h; i < len(array); i++ {
			for j := i; j >= h && array[j] < array[j - h]; j = j - h {
				algoutils.Swap(array, j, j - h)
			}
		}
		h = h/3
	}
}