package main

import "fmt"

func reverseFactorial(target int) {
	divisor, num := 2, target

	for 0 == num%divisor {
		num /= divisor
		divisor++
	}

	if num == 1 {
		fmt.Printf("%d is %d!\n", target, divisor-1)
		return
	}
	fmt.Printf("%d isn't a factorial number\n", target)
	return
}

func main() {
	reverseFactorial(720)
	reverseFactorial(120)
	reverseFactorial(24)
	reverseFactorial(362880)
	reverseFactorial(12345)
}
