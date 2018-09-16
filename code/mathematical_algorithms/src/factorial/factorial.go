package main
// Part of Cosmos by OpenGenus Foundation

import (
	"fmt"
)

func calculateFactorial(i int) int {
	if i == 0 {
		return 1
	}

	return i * calculateFactorial(i - 1)
}

func main() {
	// 120
	fmt.Println(calculateFactorial(5))

	// 6
	fmt.Println(calculateFactorial(3))

	// 5040
	fmt.Println(calculateFactorial(7))

	// 6227020800
	fmt.Println(calculateFactorial(13))
}
