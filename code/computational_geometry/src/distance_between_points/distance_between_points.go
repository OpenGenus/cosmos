package main
// Part of Cosmos by OpenGenus Foundation

import (
	"fmt"
	"math"
)

type vector struct {
	x, y float64
}

func calculateDistance(a, b vector) float64 {
	return math.Sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y))
}

func main() {
	a := vector{x: 5, y: 5}
	b := vector{x: 5, y: 10}

	// 5
	fmt.Println(calculateDistance(a, b))

	a = vector{x: 2, y: 4}
	b = vector{x: 4, y: -4}

	// 8.246
	fmt.Println(calculateDistance(a, b))
}
