// Part of Cosmos by OpenGenus Foundation
// Code contributed by Marc Tibbs

// A Dynamic Programming solution for Rod Cutting problem 
package main

import (
	"fmt"
	"math"
)

const min float64 = -1 << 63

func rodCut(price []float64, n int) float64 {
	val := []float64{0}
	val = append(val, price...)

	for i := 1; i < n+1; i++ {
		var max_val = min
		for j := 0; j < i; j++ {
			max_val = math.Max(max_val, price[j] + val[i-j-1])
		}
		val[i] = max_val
	}
	return val[n]
}

// Driver program to test rodCut function
func main() {
	arr := []float64{1, 5, 8, 9, 10, 17, 17, 20}
	var size = len(arr)
	fmt.Println("Maximum Obtainable Value is",rodCut(arr, size))
}
