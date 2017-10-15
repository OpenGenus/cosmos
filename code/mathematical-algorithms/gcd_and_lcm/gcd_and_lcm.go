package main
// Part of Cosmos by OpenGenus Foundation

import (
	"fmt"
)

func calculateGCD(a, b int) int {
	for b != 0 {
		c := b
		b = a % b
		a = c
	}

	return a
}

func calculateLCM(a, b int, integers ...int) int {
	result := a * b / calculateGCD(a, b)

	for i := 0; i < len(integers); i++ {
		result = calculateLCM(result, integers[i])
	}

	return result
}

func main() {
	// 8
	fmt.Println(calculateGCD(8, 16))

	// 4
	fmt.Println(calculateGCD(8, 12))

	// 12
	fmt.Println(calculateLCM(3, 4))

	// 1504
	fmt.Println(calculateLCM(32, 94))

	// 60
	fmt.Println(calculateLCM(4, 5, 6))

	// 840
	fmt.Println(calculateLCM(4, 5, 6, 7, 8))
}
