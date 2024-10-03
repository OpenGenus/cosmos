package main
// Part of Cosmos by OpenGenus Foundation
import (
	"fmt"
)

func binomialCoefficient(n int, k int) float64 {
	bc := make([][]float64, n+1)
	for i := range bc {
		bc[i] = make([]float64, n+1)
	}
	for i := 0; i <= n; i++ {
		bc[i][0] = 1;
	}
	for i := 0; i <= n; i++ {
		bc[i][i] = 1;
	}
	for i := 1; i <= n; i++ {
		for j := 1; j < i; j++ {
			bc[i][j] = bc[i-1][j-1] + bc[i-1][j]
		}
	}
		return bc[n][k];
}

func main() {
	fmt.Println(binomialCoefficient(10,5))
}
