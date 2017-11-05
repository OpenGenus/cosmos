package main

import "fmt"

// twoSum returns two numbers which add up to sum
func twoSum(list []float64, sum float64) (a float64, b float64, hasResult bool) {
	n := len(list)
	m := make(map[float64]bool, 0)
	for i := 0; i < n; i++ {
		m[list[i]] = true
	}
	for i := 0; i < n; i++ {
		if m[sum-list[i]] {
			return list[i], sum - list[i], true
		}
	}
	return 0.0, 0.0, false
}

func main() {
	list := []float64{1, 2, 3, 4, 5}
	sum := 8.0
	a, b, hasResult := twoSum(list, sum)
	if hasResult {
		fmt.Printf("Two numbers are (%f, %f).\n", a, b)
	} else {
		fmt.Println("There are no results.")
	}
}