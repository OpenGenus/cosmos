// Part of Cosmos by OpenGenus Foundation

package main

import (
	"fmt"
	"os"
)

func updateGap(gap int) int {
	gap = (gap * 10) / 13
	if gap < 1 {
		return 1
	}
	return gap
}

func combSort(ar []int, n int) {
	gap := n
	flag := false
	for gap > 1 || flag {
		gap = updateGap(gap)
		flag = false
		for i := 0; i < (n - gap); i++ {
			if ar[i] > ar[i+1] {
				ar[i], ar[i+1] = ar[i+1], ar[i]
				flag = true
			}
		}
	}
}

func main() {
	n := 0
	fmt.Print("Input number of elements in the array - ")
	fmt.Fscan(os.Stdin, &n)
	ar := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(os.Stdin, &ar[i])
	}

	combSort(ar, n)
	fmt.Print("Array after sorting - ")
	for i := 0; i < n; i++ {
		fmt.Println(ar[i])
	}
}
