package main

import "fmt"

// Fibonacci function to calculate nth fibonacci number 
func Fibonacci(n int) int {
	a, b := 0, 1
	fibonacci := 0
	if n == 0 {
		fibonacci = 0
	} else if n == 1 {
		fibonacci = 1
	} else {
		for i := 2; i <= n; i++ {
			// Storing result in 2 varibles instead of an array
			fibonacci = a + b
			a = b
			b = fibonacci
		}
	}
	return fibonacci
}

func main() {
	fmt.Println(Fibonacci(10)) // Output: 55
	fmt.Println(Fibonacci(0)) // Output: 0
	fmt.Println(Fibonacci(1)) // Output: 1
	fmt.Println(Fibonacci(20)) // Output: 6751
	
}
