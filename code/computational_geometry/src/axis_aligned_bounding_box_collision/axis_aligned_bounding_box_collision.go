package main
// Part of Cosmos by OpenGenus Foundation

import (
	"fmt"
	"math"
)

type vector struct {
	x, y float64
}

type shape struct {
	center vector
	height, width float64
}

func checkAABBCollision(a, b shape) bool {
	// change '<' to '<=' if you want to include edge touching as a collision
	return (math.Abs(a.center.x - b.center.x) *2 < (a.width + b.width)) &&
		(math.Abs(a.center.y - b.center.y) * 2 < (a.height + b.height))
}

func main() {
	shapeA := shape{center: vector{3, 3}, height: 5, width: 4}
	shapeB := shape{center: vector{9, 3}, height: 4, width: 6}

	// 0 - no collision
	fmt.Println(checkAABBCollision(shapeA, shapeB))

	shapeA = shape{center: vector{3, 3}, height: 5, width: 4}
	shapeB = shape{center: vector{7, 3}, height: 4, width: 6}

	// 1 - collision
	fmt.Println(checkAABBCollision(shapeA, shapeB))

	shapeA = shape{center: vector{3, 10}, height: 6, width: 4}
	shapeB = shape{center: vector{3, 5}, height: 6, width: 6}

	// 1 - collision
	fmt.Println(checkAABBCollision(shapeA, shapeB))
}
