package main

import "fmt"

// Hamming distance between two integers is the number of positions
// at which the corresponding bits are different.
func HammingDistance(x, y int) (count int) {
	t := x ^ y

	//count the number of set bits in the xor of two numbers
	for t != 0 {
		t = t & (t - 1)
		count++
	}
	return
}

func main() {
	fmt.Printf("Hamming distance beetwen (%d) and (%d) is (%d)\n", 1, 2, HammingDistance(1, 2))
}
