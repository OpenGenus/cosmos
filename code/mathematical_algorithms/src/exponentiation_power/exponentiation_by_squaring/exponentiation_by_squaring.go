package main
// Part of Cosmos by OpenGenus Foundation

import (
	"fmt"
	"math"
)

func fast_power(base,exponent int) int {
	if exponent == 0 {
		return 1
	}

	if exponent == 1 {
		return base
	}

	if exponent % 2 == 0 {
		return fast_power(base*base, exponent/2)
	} else {
		return base * fast_power(base*base, (exponent-1)/2)
	}
}
	

func main() {
	fmt.Println(fast_power(2,10)) //1024
	fmt.Println(fast_power(2,11)) //2048
	fmt.Println(fast_power(3,20)) //3486784401
	fmt.Println(fast_power(10,5)) //10000000

	var result bool = true

	m := map[int]int{ 3:10, 2:12, 4:20, 5:1, 6:0, 7:8, 31:3, 20:3};
	for k, v := range m { 
	    result = result && (float64(fast_power(k,v)) == math.Pow(float64(k),float64(v)))
	}

	if result {
		fmt.Println("Tests ok!")
	} else {
		fmt.Println("Error!")
	}
}
