package main

import (
	"fmt"
)

type Scenario struct {
	Value  int
	Denoms []int
	Result []int
}

func main() {
	scenarios := []Scenario{
		Scenario{Value: 100, Denoms: []int{50, 25, 10, 5, 1}, Result: []int{50, 50}},
		Scenario{Value: 101, Denoms: []int{50, 25, 10, 5, 1}, Result: []int{50, 50, 1}},
		Scenario{Value: 77, Denoms: []int{50, 25, 10, 5, 1}, Result: []int{50, 25, 1, 1}},
		Scenario{Value: 38, Denoms: []int{50, 25, 10, 5, 1}, Result: []int{25, 10, 1, 1, 1}},
		Scenario{Value: 17, Denoms: []int{50, 25, 10, 5, 1}, Result: []int{10, 5, 1, 1}},
		Scenario{Value: 3, Denoms: []int{50, 25, 10, 5, 1}, Result: []int{1, 1, 1}},
		Scenario{Value: 191, Denoms: []int{100, 50, 25, 10, 5, 1}, Result: []int{100, 50, 25, 10, 5, 1}},
	}

	for _, s := range scenarios {
		result := getMinimumCoins(s.Value, s.Denoms)
		if fmt.Sprint(result) != fmt.Sprint(s.Result) {
			fmt.Println("Test Failed: Value: ", s.Value, ", Denominations: ", s.Denoms, ", Expected Result: ", s.Result, ", Actual Result: ", result)
		}
	}
}

func getMinimumCoins(value int, denoms []int) []int {
	var result []int
	for _, d := range denoms {
		for {
			if value < d {
				break
			}
			result = append(result, d)
			value -= d
		}
	}
	return result
}
