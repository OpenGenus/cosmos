package main

import (
	"fmt"
	"strconv"
)

func main() {
	for num := 0; num <= 1000000; num++ {
		if isAutomorphic(num) {
			fmt.Println(num, " ", (num * num))
		}
	}
}

func isAutomorphic(num int) bool {
	strNum := strconv.Itoa(num)
	strSquareNum := strconv.Itoa(num * num)
	lenNum := len(strNum)
	lenSquareNum := len(strSquareNum)
	return strNum == strSquareNum[lenSquareNum-lenNum:]
}
