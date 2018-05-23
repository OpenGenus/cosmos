package main

import (
	"math/rand"
)

func quickselect(list []int, item_index int) int {
	return selec(list,0, len(list) - 1, item_index)
}

func partition(list []int, left int, right int, pivotIndex int) int {
	pivotValue := list[pivotIndex]

	// move pivot to end
	list[pivotIndex], list[right] = list[right], list[pivotIndex]

	storeIndex := left

	for i := left; i < right; i++ {
		if list[i] < pivotValue {
			// move pivot to its final place
			list[storeIndex], list[i] = list[i], list[storeIndex]
			storeIndex += 1
		}
	}
	list[right], list[storeIndex] = list[storeIndex], list[right]

	return storeIndex
}

func selec(list []int, left int, right int, k int) int {

	if left == right {
		return list[left]
	}

	pivotIndex := rand.Intn(right)
	// the pivot in its final sorted position
	pivotIndex = partition(list, left, right, pivotIndex)

	if k == pivotIndex {
		return list[k]
	} else if k < pivotIndex {
		return selec (list, left, pivotIndex - 1, k)
	} else {
		return selec(list, pivotIndex + 1, right, k)
	}
}

func main() {}