/* Part of Cosmos by OpenGenus Foundation */
package main

import "fmt"

type MaxHeap struct {
	data []int
}

func swap(x, y int) (int, int) {
	return y, x
}

func (h *MaxHeap) Push(value int) {
	h.data = append(h.data, value)
	index := len(h.data) - 1
	parent := (index - 1) / 2
	for index > 0 && h.data[index] > h.data[parent] {
		h.data[index], h.data[parent] = swap(h.data[index], h.data[parent])
		index = parent
		parent = (index - 1) / 2
	}
}
func (h *MaxHeap) Top() int {
	return h.data[0]
}
func (h *MaxHeap) ExtractTop() int {
	index := len(h.data) - 1
	max := h.Top()
	h.data[0], h.data[index] = swap(h.data[0], h.data[index])
	h.data = h.data[:index]
	h.heapify(0)
	return max
}

func (h *MaxHeap) Pop() {
	index := len(h.data) - 1
	h.data[0], h.data[index] = swap(h.data[0], h.data[index])
	h.data = h.data[:index]
	h.heapify(0)
}

func (h *MaxHeap) heapify(index int) {
	left := (index * 2) + 1
	right := left + 1
	target := index

	if left < len(h.data) && h.data[left] > h.data[index] {
		target = left
	}
	if right < len(h.data) && h.data[right] > h.data[target] {
		target = right
	}
	if target != index {
		h.data[index], h.data[target] = swap(h.data[index], h.data[target])
		h.heapify(target)
	}

}

func (h *MaxHeap) Empty() bool {
	return len(h.data) == 0
}

func main() {
	data := []int{45, 6, 4, 3, 2, 72, 34, 12, 456, 29, 312}
	var h MaxHeap

	for _, v := range data {
		h.Push(v)
	}

	fmt.Println("Current Data is ", h.data)
	for !h.Empty() {
		fmt.Println(h.Top())
		h.Pop()
	}
}
