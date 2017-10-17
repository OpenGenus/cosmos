package main

import "fmt"

func squareRoot(n int) float64 {
	x := float64(n)
	nF := float64(n)
	e := 0.000001

	for x - (nF/x) > e {
	    x = ((nF/x)+x)/2
	}

	return x
}


func main() {
	a := 90
    fmt.Printf("The square root of %v is %v \n", a, squareRoot(a))
}
