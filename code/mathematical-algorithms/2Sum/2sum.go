// Part of Cosmos by OpenGenus Foundation
package main

import "fmt"

func twoSum(data []int, index map[int]bool, target int) {
	for i := range data {
		if index[target-data[i]] {
			fmt.Printf("We can get %d use %d and %d in %v\n", target, data[i], target-data[i], data)
			return
		}
	}
	fmt.Printf("We can't get %d by combime two numbers in %v\n", target, data)
	return
}

func main() {
	data := []int{1, 2, 3, 4, 5, 6, 7, 7, 8, 9, 10, 12, 13}
	index := make(map[int]bool)

	for i := range data {
		index[data[i]] = true
	}

	twoSum(data, index, 5)
	twoSum(data, index, 22)
	twoSum(data, index, 33)
	twoSum(data, index, 123)
}
