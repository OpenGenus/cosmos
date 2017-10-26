// Part of Cosmos by OpenGenus Foundation
package main

import "fmt"

func factorial(num int) int {
	if num == 0 {
		return 1
	}
	return (num * factorial(num-1))
}

func main() {
	num := 5
	fmt.Println(factorial(num))
}
