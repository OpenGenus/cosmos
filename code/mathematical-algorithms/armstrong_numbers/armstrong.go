package main

import (
	"fmt"
	"math"
)

// Part of Cosmos by OpenGenus Foundation
// Lists all possible armstrong numbers from 0 to 999
func listAM() {
	count := 0

	for a := 0; a < 10; a++ {
		for b := 0; b < 10; b++ {
			for c := 0; c < 10; c++ {
				abc := (a * 100) + (b * 10) + (c)
				if abc == (cube(a) + cube(b) + cube(c)) {
					count++
					fmt.Printf("%d: %d\n", count, abc)
				}
			}
		}
	}
}

func cube(n int) int {
	return int(math.Pow(float64(n), 3.0))
}

func main() {
	listAM()
}
