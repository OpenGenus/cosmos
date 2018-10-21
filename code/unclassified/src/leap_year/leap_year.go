package main

import "fmt"

func isLeapyear(year int) bool {
	if year%400 == 0 {
		return true
	}
	if year%100 == 0 {
		return false
	}
	if year%4 == 0 {
		return true
	}

	return false
}

func leapYearsInRange(min, max int) []int {
	var res []int
	for i := min; i <= max; i++ {
		if isLeapyear(i) {
			res = append(res, i)
		}
	}

	return res
}

func main() {
	res := leapYearsInRange(2010, 2030)
	for _, year := range res {
		fmt.Println(year)
	}
	/*
	 * Output:
	 * 2012
	 * 2016
	 * 2020
	 * 2024
	 * 2028
	 */
}
