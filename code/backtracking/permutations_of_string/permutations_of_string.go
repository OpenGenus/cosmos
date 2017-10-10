// Part of Cosmos by OpenGenus Foundation
package main

import "fmt"

func permutation(data []byte, start, end int) {
	if start == end {
		fmt.Println(string(data))
	} else {
		for i := start; i <= end; i++ {
			data[start], data[i] = data[i], data[start]
			permutation(data, start+1, end)
			data[start], data[i] = data[i], data[start]
		}
	}
}

func main() {
	data := string("ABC")
	byteArray := []byte(data)

	permutation(byteArray, 0, len(byteArray)-1)
}
