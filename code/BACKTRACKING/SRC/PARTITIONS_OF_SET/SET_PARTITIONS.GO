/// Part of Cosmos by OpenGenus Foundation
package main

import "fmt"

var totalSol int

/*
expected output:
solution 1
[1 2 3]
solution 2
[1 2]
[3]
solution 3
[1 3]
[2]
solution 4
[1]
[2 3]
solution 5
[1]
[2]
[3]
*/
func setPartition(data []int, indexArr []int, index, currentLevel int) {
	if index == len(data) {
		totalSol++
		fmt.Printf("solution %d\n", totalSol)
		for level := 0; level <= currentLevel; level++ {
			ans := []int{}
			for i, v := range indexArr {
				if v == level {
					ans = append(ans, data[i])
				}
			}
			fmt.Println(ans)
		}
		return
	}

	//Try eveny level within currentLevel for current index
	for i := 0; i <= currentLevel; i++ {
		indexArr[index] = i
		setPartition(data, indexArr, index+1, currentLevel)
	}

	//Move to next level
	indexArr[index] = currentLevel + 1
	currentLevel++
	setPartition(data, indexArr, index+1, currentLevel)
	currentLevel--
}

func main() {
	data := []int{1, 2, 3}

	//Use index array to indicate which partition the element belong to
	index := make([]int, len(data))

	//Since {1},{2,3} is equal to {2,3},{1},
	//We can always put first element in first partition and generate the partition of the rest of elements.
	index[0] = 0
	totalSol = 0
	setPartition(data, index, 1, 0)
}
