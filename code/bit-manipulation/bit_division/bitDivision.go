package main
// Part of Cosmos by OpenGenus Foundation
import (
	"fmt"
	"math"
	"errors"
)

func divide(dividend int, divisor int) (int, error) {
	var positive bool = false
	var answer int = 0

	if divisor == 0 {
		return 0, errors.New("cannot divide by zero")
	}

	if dividend > 0 && divisor > 0 {
		positive = true
	}

	dividend = int(math.Abs(float64(dividend)))
	divisor = int(math.Abs(float64(divisor)))

	for dividend >= divisor {
		temp, i := divisor, 1
		for dividend >= temp {
			dividend -= temp
			answer += i
			i <<= 1
			temp <<= 1
		}
	}
 
	if !positive {
		answer = -answer
	}

	return answer, nil
}

