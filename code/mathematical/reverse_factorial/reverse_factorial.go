/*
 * Part of Cosmos by OpenGenus Foundation
 */
package main

/*
Excepted outpout
720 is 6!
120 is 5!
24 is 4!
362880 is 9!
12345 isn't a factorial number

*/
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
