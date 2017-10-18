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

func reverseNumber(n int) string {
	splits := strings.Split(strconv.Itoa(n), "")
	sort.Sort(sort.Reverse(sort.StringSlice(splits)))
	return strings.Join(splits, "")
}
