package main

import (
	"fmt"
	"strconv"
)

func safePosition(n int,k int) int {
	if n <= 1 {
		return 0
	}
	return (safePosition(n-1, k) + k) % n
}

func main() {
	var n int
	var k int
	fmt.Println("Enter the number of people:")
	fmt.Scanf("%d\n", &n)
	fmt.Println("Enter the kth value of people getting executed:")
	fmt.Scanf("%d\n", &k)

	fmt.Println("Safe Position is " + strconv.Itoa(safePosition(n, k) + 1))
}