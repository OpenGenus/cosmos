// Part of Cosmos by OpenGenus Foundation

package main

import "fmt"

var totalSol int

/*

Expected output:
[1 2 3]
[1 5]
[2 4]
[6]
There're  4 ways to combine 6 from [1 2 3 4 5 6 7 8 9 10 11 12 13 14]

*/

func subSetSum(data []int, sol []int, index, target int) {
	if target == 0 {
		totalSol++
		fmt.Println(sol)
		return
	}

	if target < 0 || index >= len(data) {
		return
	}

	sol = append(sol, data[index])
	subSetSum(data, sol, index+1, target-data[index])
	sol = sol[:len(sol)-1]
	subSetSum(data, sol, index+1, target)

}

func main() {
	data := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}
	sol := []int{}
	target := 6

	totalSol = 0
	subSetSum(data, sol, 0, target)
	fmt.Printf("There're  %d ways to combine %d from %v\n", totalSol, target, data)
}
