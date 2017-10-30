//Part of Open Genus foundation
package main

/*
{1 2 3 }
{1 2 }
{1 3 }
{1 }
{2 3 }
{2 }
{3 }
{}
*/

import "fmt"

func powerSet(input, record []int, index int) {
	if index == len(input) {
		fmt.Printf("{")
		for i, v := range record {
			if v == 1 {
				fmt.Printf(" %v", input[i])
			}
		}
		fmt.Printf(" }\n")
		return
	}

	record[index] = 1
	powerSet(input, record, index+1)
	record[index] = 0
	powerSet(input, record, index+1)

}

func main() {
	input := []int{1, 2, 3}
	record := make([]int, len(input))

	powerSet(input, record, 0)
}
