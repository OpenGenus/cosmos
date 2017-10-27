package main
// Part of Cosmos by OpenGenus Foundation
import "fmt"

//Returns the nth term in the Fibonacci Sequence
func fibonacci(n int) int {
	if n <= 0 {
		return 0
	}
	if n == 1 {
		return 1
	}
	return fibonacci(n-1) + fibonacci(n-2)
}

//Fibonacci 30 and over can take a long time to compute. 
func main() {
	fmt.Println(fibonacci(10)) 
	fmt.Println(fibonacci(8))
	fmt.Println(fibonacci(5))
	fmt.Println(fibonacci(2))
}
