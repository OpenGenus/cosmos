// Part of Cosmos by OpenGenus Foundation
package main

import "fmt"

func max(n1, n2 int) int {
	if n1 > n2 {
		return n1
	}
	return n2
}

func maxSubArraySum(data []int) int {
	result := data[0]
	current_max := max(data[0], 0)

	for i := 1; i < len(data); i++ {
		current_max += data[i]
		result = max(result, current_max)
		current_max = max(current_max, 0)
	}

	return result
}

func main() {
	input := []int{-3, 2, -1, 4, -5}
	input2 := []int{-1, -2, -3, -4, -5}

	fmt.Printf("The max sum of %v is %d\n", input, maxSubArraySum(input))
	fmt.Printf("The max sum of %v is %d\n", input2, maxSubArraySum(input2))
}
