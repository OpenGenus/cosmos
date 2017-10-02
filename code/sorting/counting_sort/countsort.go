package main

import "fmt"

const MaxUint = ^uint(0)
const MaxInt = int(MaxUint >> 1)
const MinInt = -MaxInt - 1

var list = []int{12, 3, 4, 1, 2, 3, 5, 42, 34, 61, 2, 3, 5}

func countingSort(list []int) {
	maxN := MinInt
	for _, v := range list {
		if v > maxN {
			maxN = v
		}
	}
	fmt.Println(maxN)

	count := make([]int, maxN+1)

	for _, x := range list {
		count[x]++
	}
	z := 0
	for i, c := range count {
		for ; c > 0; c-- {
			list[z] = i
			z++
		}
	}
}

func main() {
	fmt.Println("before sorting", list)
	countingSort(list)
	fmt.Println("after sorting", list)
}
