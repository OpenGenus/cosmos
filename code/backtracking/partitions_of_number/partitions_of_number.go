/// Part of Cosmos by OpenGenus Foundation
package main

import "fmt"

var totalSol int

func partitions(input int, sol []int, start int) {
	if input == 0 {
		fmt.Println(sol)
		totalSol++
		return
	}

	for i := start; i <= input; i++ {
		sol = append(sol, i)
		partitions(input-i, sol, i)
		sol = sol[:len(sol)-1]

	}
}

func main() {
	input := 10
	sol := []int{}
	totalSol = 0
	partitions(input, sol, 1)
	fmt.Printf("There are %d ways to combine %d\n", totalSol, input)
}
