package main

import "fmt"

func XorSwap(r1 *int, r2 *int) {
	*r1 = *r1 ^ *r2
	*r2 = *r1 ^ *r2
	*r1 = *r1 ^ *r2

	return
}

func main() {
	A := 10
	B := 15

	fmt.Printf("Before swapping: A = %d and B = %d\n", A, B)

	XorSwap(&A, &B)

	fmt.Printf("After swapping: A = %d and B = %d\n", A, B)
}
