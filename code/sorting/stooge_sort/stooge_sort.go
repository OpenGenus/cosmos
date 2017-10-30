/* Part of Cosmos by OpenGenus Foundation */
package main

import "fmt"

/*
* If the value at the start is larger than the value at the end, swap them.
* If there are 3 or more elements in the list, then:
* Stooge sort the initial 2/3 of the list
* Stooge sort the final 2/3 of the list
* Stooge sort the initial 2/3 of the list again
 */

func stoogeSort(data []int, start, end int) {
	if data[start] > data[end] {
		data[start], data[end] = data[end], data[start]
	}

	if (end - start) >= 2 {
		third := (end - start + 1) / 3
		stoogeSort(data, start, end-third)
		stoogeSort(data, start+third, end)
		stoogeSort(data, start, end-third)

	}
}

func main() {
	data := []int{42, 32, 65, 12345, 41, 52, 23, 1, 25, 1245, 84, 582, 184, 123, 561}
	fmt.Println("Before sorting", data)
	stoogeSort(data, 0, len(data)-1)
	fmt.Println("After orting", data)
}
