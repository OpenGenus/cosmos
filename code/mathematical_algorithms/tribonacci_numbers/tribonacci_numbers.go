package main

import "fmt"

// Prints series of 'n' tribonacci numbers

func tribonacci(n int) {
	a, b, c := 0, 1, 1
	fmt.Printf("%d, %d, %d, ", a, b, c)
	for i := 3; i < n; i++ {
		d := a + b + c
		a, b, c = b, c, d
		fmt.Printf("%d, ", d)
	}
}

func main() {
	tribonacci(15)
}
