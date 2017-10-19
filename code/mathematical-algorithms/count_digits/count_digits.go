// Part of Cosmos by OpenGenus Foundation
package main

/*
Expected output
123,  number of digits is 3
0,  number of digits is 1
6523123,  number of digits is 7
*/

import "fmt"

func countDigits(target int) int {
	if target == 0 {
		return 1
	}

	count := 0
	for target != 0 {
		target /= 10
		count++
	}
	return count
}

func main() {
	fmt.Printf("%d,  number of digits is %d\n", 123, countDigits(123))
	fmt.Printf("%d,  number of digits is %d\n", 0, countDigits(0))
	fmt.Printf("%d,  number of digits is %d\n", 6523123, countDigits(6523123))
}
