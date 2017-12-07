// Part of Cosmos by OpenGenus Foundation
package main

import (
	"fmt"
)

func prime_factors(target int) {
	n := target
	ans := []int{}
	for d := 2; d*d <= n; d++ {
		if n%d == 0 {
			ans = append(ans, d)

			for n%d == 0 {
				n /= d
			}
		}
	}
	if n > 1 {
		ans = append(ans, n)
	}
	fmt.Printf("The prime factors of %d is %v\n", target, ans)
}

func main() {
	var i int
	fmt.Print("Enter number: ")
	fmt.Scan(&i)
	prime_factors(i)
}
