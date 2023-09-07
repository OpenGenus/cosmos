// Median finds median in array of numbers.
// Part of Cosmos by OpenGenus Foundation
package main

import (
	"strings"
	"sort"
	"fmt"
)

// Median sorts the slice and returns the median of the numbers.
func Median(nums []int) int {
	sort.Ints(nums)
	length := len(nums)
	if odd := length % 2; odd == 1 {
		return nums[(length - 1) / 2]
	}
	return (nums[length / 2] + nums[(length / 2) - 1]) / 2
}

func main() {
	examples := []struct{
		desc string
		in []int
		want int
	}{
		{
			desc: "pre-sorted odd count",
			in: []int{0,1,2,3,4},
			want: 2,
		},
		{
			desc: "pre-sorted even count",
			in: []int{1,2,3,4,5,6},
			want: 3,
		},
		{
			desc: "unsorted even count",
			in: []int{15,7,27,0,-1,100},
			want: 11,
		},
		{ 
			desc: "unsorted odd count",
			in: []int{35,3,-10,100,89,91,14},
			want: 35,
		},
		{
			desc: "unsorted odd with duplicates",
			in: []int{17,17,17,49,-10,7,7,100,85},
			want: 17,
		},
	}

	for _, e := range examples {
		var s strings.Builder
		fmt.Fprintf(&s, "%s\n", e.desc)
		got := Median(e.in)
		fmt.Fprintf(&s, "got %d", got)
		if got != e.want {
			fmt.Fprintf(&s, ", want %d", e.want)
		}
		fmt.Println(s.String())
	}
}