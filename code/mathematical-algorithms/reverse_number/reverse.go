package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	num := 123456789
	fmt.Println("reverse of", num, "is", reverseNumber(num))
}

func reverseNumber(n int) int {
	splits := strings.Split(strconv.Itoa(n), "")
	sort.Sort(sort.Reverse(sort.StringSlice(splits)))
	i, _ := strconv.Atoi(strings.Join(splits, ""))
	return i
}


