package main

// Part of Cosmos by OpenGenus Foundation
import "fmt"

func averageStreamNumbers(input []int) {
	average := 0
	sum := 0
	n := 0

	getAverage := func(input int) int {
		sum += input
		n++
		return sum / n

	}

	for i := range input {
		average = getAverage(input[i])
		fmt.Printf("Average of %d numbers is %d\n", i+1, average)
	}
}

func main() {
	input := []int{10, 20, 30, 40, 50, 60, 70, 80}
	averageStreamNumbers(input)
}
