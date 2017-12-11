// Part of Cosmos by OpenGenus Foundation
// @Author: Chanwit Piromplad
// @Date: 2017-10-15 20:57

package main

import (
	"fmt"
)

func isPowerOf2(n int) bool {
	return n > 0 && (n&(n-1) == 0)
}

func main() {
	fmt.Println(isPowerOf2(64))
}
