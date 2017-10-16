package main
// Part of Cosmos by OpenGenus Foundation
import "fmt"

const MaxUint = ^uint(0)
const MaxInt = int(MaxUint >> 1)
const MinInt = -MaxInt - 1

var list = []int{-5, 12, 3, 4, 1, 2, 3, 5, 42, 34, 61, 2, 3, 5}

func countingSort(list []int) {
	maxNumber := MinInt
	minNumber := MaxInt
	for _, v := range list {
		if v > maxNumber {
			maxNumber = v
		}
		if v < minNumber {
			minNumber = v
		}
	}

	count := make([]int, maxNumber-minNumber+1)

	for _, x := range list {
		count[x-minNumber]++
	}
	index := 0
	for i, c := range count {
		for ; c > 0; c-- {
			list[index] = i + minNumber
			index++
		}
	}
}

func main() {
	fmt.Println("before sorting", list)
	countingSort(list)
	fmt.Println("after sorting", list)
}
