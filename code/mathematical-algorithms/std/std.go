package main

// Part of Cosmos by OpenGenus Foundation

import (
	"fmt"
	"math"
)

// Mean calculates the mean value of a given slice. If an empty slice is given
// it will return a zero mean by convention.
func Mean(x []float64) float64 {
	sum := 0.0
	n := len(x)
	if n == 0 {
		return sum
	}
	for i := 0; i < n; i++ {
		sum = sum + x[i]
	}
	return sum / float64(n)
}

// Variance calculates the variance from the mean of a given slice. If an empty
// slice is given it will return a zero variance by convention.
func Variance(x []float64) float64 {
	variance := 0.0
	n := len(x)
	if n == 0 {
		return variance
	}
	mean := Mean(x)
	for i := 0; i < n; i++ {
		variance += (x[i] - mean) * (x[i] - mean)
	}
	return variance / float64(n)
}

// Std returns the standard deviation of a given slice.
func Std(x []float64) float64 {
	return math.Sqrt(Variance(x))
}

func main() {
	x := []float64{12, 65, 91, 52, 18, 72}
	fmt.Println(Std(x))
}
