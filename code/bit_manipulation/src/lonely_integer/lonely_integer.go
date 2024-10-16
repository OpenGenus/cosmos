/*
Part of Cosmos by OpenGenus Foundation
The Lonely Integer Problem
Given an array in which all the no. are present twice except one, find that lonely integer.
*/

package main

import "fmt"

func LonelyInteger(a []int) int{
	lonely := 0
	for i := 0; i < len(a); i++ {
		lonely ^= a[i]
	}
	return lonely
}

func main() {
	a := []int{2,3,4,5,3,2,4}
	fmt.Println(LonelyInteger(a))
}