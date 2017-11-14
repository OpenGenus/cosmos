// Part of Cosmos by OpenGenus Foundation
package main

import "fmt"

func zeroToFive(input int) int {
	div := 1
	ans := 0

	for (input / div) > 0 {
		tmp := (input / div) % 10

		if tmp == 0 {
			ans = 5*div + ans
		} else {
			ans = tmp*div + ans
		}

		div *= 10
	}
	return ans
}

func main() {
	fmt.Printf("Change %d to %d\n", 10203, zeroToFive(10203))
	fmt.Printf("Change %d to %d\n", 57123, zeroToFive(57123))
	fmt.Printf("Change %d to %d\n", 2901031, zeroToFive(2901031))
}
