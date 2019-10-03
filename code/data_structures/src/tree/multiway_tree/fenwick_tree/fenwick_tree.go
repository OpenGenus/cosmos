package main

import "fmt"

type FenwickTree struct {
	N   int
	arr []int
}

func (bit *FenwickTree) Initialize(n int) {
	fmt.Println(n)
	bit.N = n
	bit.arr = make([]int, n+1)
}

func (bit *FenwickTree) lsb(idx int) int {
	return idx & -idx
}

func (bit *FenwickTree) Update(idx int, val int) {
	for ; idx <= bit.N; idx += bit.lsb(idx) {
		bit.arr[idx] += val
	}
}

func (bit *FenwickTree) PrefixSum(idx int) int {
	sum := 0

	for ; idx > 0; idx -= bit.lsb(idx) {
		sum += bit.arr[idx]
	}

	return sum
}

func (bit *FenwickTree) RangeSum(l int, r int) int {
	return bit.PrefixSum(r) - bit.PrefixSum(l-1)
}

func main() {
	arr := []int{1, 2, 3, 4, 5}
	n := len(arr)

	var fenwick FenwickTree
	fenwick.Initialize(n)

	for i := 0; i < n; i++ {
		fenwick.Update(i+1, arr[i])
	}

	fmt.Printf("Range sum from 2 to 4: %v\n", fenwick.RangeSum(2, 4))
	fmt.Printf("Range sum from 1 to 5: %v\n", fenwick.RangeSum(1, 5))
}
