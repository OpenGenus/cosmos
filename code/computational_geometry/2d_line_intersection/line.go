package main

import "fmt"

type Vector struct {
	x float64
	y float64
}

func intersection(v1 *Vector, v2 *Vector, v3 *Vector, v4 *Vector) (res *Vector, isParallel bool) {
	x12 := v1.x - v2.x
	x34 := v1.y - v2.y
	y12 := v3.x - v4.x
	y34 := v3.y - v4.y

	c := x12*y34 - y12*x34

	if c == 0.0 {
		return nil, true
	}

	a := v1.x*v2.y - v1.y*v2.x
	b := v3.x*v4.y - v3.y*v4.x

	res = &Vector{
		x: (a*x34 - b*x12) / c,
		y: (a*y34 - b*y12) / c,
	}
	return res, false
}

func main() {
	v1 := &Vector{x: 10.0, y: 3.0}
	v2 := &Vector{x: 20.0, y: 10.0}
	v3 := &Vector{x: 10.0, y: 10.0}
	v4 := &Vector{x: 20.0, y: 3.0}

	intersectionPoint, isParallel := intersection(v1, v2, v3, v4)
	if isParallel {
		fmt.Println("No intersection")
	} else {
		fmt.Printf("Intersection: (%f, %f)\n", intersectionPoint.x, intersectionPoint.y)
	}
}
