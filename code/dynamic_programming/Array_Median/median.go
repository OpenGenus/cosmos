//binary median prints the median value of a list of elements in an array
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

//Part of Cosmos by OpenGenus Foundation
func main() {
	//length is the length of the array
	var length int
	//median is the median value of the array and by default initialized to zero
	var median float32
	fmt.Println("Enter the Length of the array")
	fmt.Scanf("%d", &length)
	//array declared with a size equal to the length
	var array []int
	scanner := bufio.NewScanner(os.Stdin)
	//i keeps track of the array length and breaks the os.Stdin loop
	i := 0
	for scanner.Scan() {
		element, err := strconv.Atoi(scanner.Text())
		if err != nil {
			//error in parsing the input. break the loop and print the error
			fmt.Printf("unable to parse integer input, %v", err)
			break
		}
		array = append(array, element)
		i++
		if i == length {
			//array length is met, hence break the os.Stdin input
			break
		}
	}
	//sort the array
	sort.Ints(array)
	if length%2 == 0 {
		median = (float32)(array[length/2]+array[(length/2)-1]) / 2
		fmt.Println(median)
		return
	}
	//median calculation for an array with odd elements. example: 7/2 = 3, hence print array[3] which is the 4th element since array index starts from zero
	median = (float32)(array[length/2])
	fmt.Println(median)
}
