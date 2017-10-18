package main

import "fmt"

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func coprime(a, b int) bool {
	return gcd(a, b) == 1
}

func main() {
	a := 14
	b := 15
	fmt.Printf("Are %v and %v coprime? %v\n", a, b, coprime(a, b))
}
