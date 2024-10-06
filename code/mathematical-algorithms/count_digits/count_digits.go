package main

import "fmt"

func countDigits(n int) int {
	count := 0

	if n == 0 {
		return 1
  }

  for n != 0 {
    count++
    n /= 10
  }

  return count
}

func main() {
  a := 154
  fmt.Printf("How many digits are in %v ? %v\n", a, countDigits(a))
}