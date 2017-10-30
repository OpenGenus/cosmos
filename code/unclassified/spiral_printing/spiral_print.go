package main

import "fmt"

// Part of Cosmos by OpenGenus Foundation
func PrintSpiral(list [][]int, rows, cols int) {
	var T, B, L, R, dir int = 0, rows - 1, 0, cols - 1, 0

	for {
		if T >= B || L >= R {
			break
		}
		// 0 - traverse right (going Left to Right)
		if dir == 0 {
			for i := 0; i <= R; i++ {
				fmt.Println(list[T][i])
			}
			T++
			dir = 1
		}
		// 1 - traverse down (going Top to Bottom)
		if dir == 1 {
			for i := T; i <= B; i++ {
				fmt.Println(list[i][R])
			}
			R--
			dir = 2
		}
		// 2 - traverse left
		if dir == 2 {
			for i := R; i >= L; i-- {
				//fmt.Println("---> ", R, i)
				fmt.Println(list[B][i])
			}
			B--
			dir = 3
		}
		// 3 - traverse up
		if dir == 3 {
			for i := B; i >= T; i-- {
				fmt.Println(list[i][L])
			}
			L++
			dir = 0
		}
	}
}

func main() {
	l := [][]int{
		{2, 4, 6, 8},
		{5, 9, 12, 16},
		{1, 11, 5, 9},
		{3, 2, 1, 8},
	}

	m := len(l) // number of rows
	n := len(l) // number of columns
	PrintSpiral(l, m, n)
}
