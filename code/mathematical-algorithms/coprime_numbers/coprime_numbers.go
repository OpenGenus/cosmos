package main

import "fmt"

func gcd(a, b int) int {
	for b != 0 {
		tmp := a % b
		a = b
		b = tmp
	}
	return a
}

func coprime(a, b int) bool {
	if a > b {
		return gcd(a, b) == 1
	} else {
		return gcd(b, a) == 1
	}
}

func main() {
	a := 15
	b := 14
	fmt.Printf("Are %v and %v coprime? %v\n", a, b, coprime(a, b))
}
