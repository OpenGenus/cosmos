package main

import (
	"fmt"
	"math"
)

func square_check(a float64) int {

	var int_root int
	var float_root float64
	
	int_root = int(math.Sqrt(a))
	float_root = math.Sqrt(a)

	if float_root - float64(int_root) != 0 {
		return -1
	} else {
		return 1
	}

}

func main() {

	var res int
	var user_value float64

	fmt.Scan(&user_value)

	res = square_check(user_value)

	if res == 1 {
		fmt.Printf("Number is a perfect square\n")
	} else {
		fmt.Printf("Number is not a perfect square\n")
	}
}
