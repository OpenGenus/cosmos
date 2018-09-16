// Part of Cosmos by OpenGenus Foundation
package main

import "fmt"
import "math"

func isSquare(input int) bool {
	if input < 0 {
		return false
	}

	root := int(math.Sqrt(float64(input)))
	return root*root == input
}

func main() {

	fmt.Printf("%d is square :%v\n", 16, isSquare(16))
	fmt.Printf("%d is square :%v\n", 13, isSquare(13))
	fmt.Printf("%d is square :%v\n", 316, isSquare(316))
}
