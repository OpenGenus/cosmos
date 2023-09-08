package main

import "fmt"

func russianPeasant(a, b int) int {
	// Init result
	res := 0

	//While second munber doesn't become 1
	for b > 0 {
		// If second number is odd, add first number to result
		if (b & 1) != 0 {
			res += a
		}
		// Double the first number
		a = a << 1
		// Halve the second number
		b = b >> 1
	}
	return res
}

func main() {
	fmt.Println(russianPeasant(18, 24))
	fmt.Println(russianPeasant(20, 12))
}
