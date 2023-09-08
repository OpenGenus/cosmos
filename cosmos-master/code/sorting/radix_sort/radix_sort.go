/* Part of Cosmos by OpenGenus Foundation */
package main

import "fmt"

const MaxUint = ^uint(0)
const MaxInt = int(MaxUint >> 1)
const MinInt = -MaxInt - 1

func radix_sort(data []int) {
	maxNumber := MinInt
	for _, v := range data {
		if v > maxNumber {
			maxNumber = v
		}
	}

	n := 1
	bucket := make([][]int, 10)
	for n <= maxNumber {
		for _, v := range data {
			bucket[(v/n)%10] = append(bucket[(v/n)%10], v)
		}
		n *= 10

		k := 0
		for i, v := range bucket {
			for _, d := range v {
				data[k] = d
				k++
			}
			bucket[i] = bucket[i][:0]
		}
	}
}

func main() {
	data := []int{43, 123, 51, 5, 1, 4, 7, 234, 6123, 5123, 11, 23, 5123}

	fmt.Println("Before sorting", data)
	radix_sort(data)
	fmt.Println("Adfter sorting", data)
}
