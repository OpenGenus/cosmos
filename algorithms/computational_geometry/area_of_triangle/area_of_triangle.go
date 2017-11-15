package main
// Part of Cosmos by OpenGenus Foundation

import (
	"fmt"
	"math"
)

type vector struct {
	x, y float64
}

func calculateArea(a, b, c vector) float64 {
	return math.Abs((a.x - b.x) * (c.y - b.y) - (a.y - b.y) * (c.x - b.x)) / 2
}

func main() {
	a := vector{x: 5, y: 5}
	b := vector{x: 5, y: 10}
	c := vector{x: 10, y: 5}

	// 12.5
	fmt.Println(calculateArea(a, b, c))

	a = vector{x: 2, y: 4}
	b = vector{x: 3, y: 12}
	c = vector{x: 8, y: 5}

	// 23.5
	fmt.Println(calculateArea(a, b, c))
}
