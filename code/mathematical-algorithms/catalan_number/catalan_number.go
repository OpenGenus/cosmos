package main

import "fmt"

func main() {
	for i := 0; i < 10; i++ {
		fmt.Println(catalan(i))
	}
}

func catalan(i int) int {
	coeff := binomialCoeff(2*i, i)
	return coeff / (i + 1)
}

func binomialCoeff(n, k int) int {
	res := 1

	if k > n-k {
		k = n - k
	}

	for j := 0; j < k; j++ {
		res *= (n - j)
		res /= (j + 1)
	}

	return res
}
