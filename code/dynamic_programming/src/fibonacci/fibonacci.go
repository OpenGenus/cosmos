// Fibonacci calculates the nth element of Fibonacci.
// Part of Cosmos by OpenGenus Foundation.
package main

import (
	"fmt"
)

// fibonacci uses a non-recursive bottom-up approach
// to calculate the nth element.
func fibonacci(n int) int {
	if n == 1 || n == 2 {
		return 1
	}
	res := make(map[int]int, n+1)
	res[1] = 1
	res[2] = 1
	for i := 3; i <= n; i++ {
		res[i] = res[i-1] + res[i-2]
	}
	return res[n]
}

func main() {
	fmt.Println(fibonacci(6))  // 8
	fmt.Println(fibonacci(10)) // 55
	fmt.Println(fibonacci(35)) // 9227465
	fmt.Println(fibonacci(70)) // 190392490709135
}
