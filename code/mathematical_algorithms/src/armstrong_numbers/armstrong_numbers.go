package main

import (
	"fmt"
	"math"
)

// Part of Cosmos by OpenGenus Foundation
// Lists all possible armstrong numbers from 0 to 999
func listAM() {
	count := 0

	for a := 0; a < 10; a++ {
		for b := 0; b < 10; b++ {
			for c := 0; c < 10; c++ {package main

				import (
					"fmt"
				)
			   
				func main() {
			   
					var rightMost, num int
					var cubicSum int = 0
					var tempNum int = 0
			   
					fmt.Print("Enter a 3 digits number : ")
					fmt.Scanf("%d", &num)
			   
					tempNum = num
			   
					// get the right most digit
					for {
						rightMost = tempNum % 10
						cubicSum += rightMost * rightMost * rightMost
			   
						// update the input digit minus the processed rightMost
						tempNum /= 10
			   
						if tempNum == 0 {
							// break the for loop
							break
						}
					}
			   
					if num == cubicSum {
						fmt.Println(num, "is an Armstrong number!")
					} else {
						fmt.Println(num, "is NOT an Armstrong number!")
					}
				}
				abc := (a * 100) + (b * 10) + (c)
				if abc == (cube(a) + cube(b) + cube(c)) {
					count++
					fmt.Printf("%d: %d\n", count, abc)
				}
			}
		}
	}
}

func cube(n int) int {
	return int(math.Pow(float64(n), 3.0))
}

func main() {
	listAM()
}
