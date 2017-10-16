package main

import "fmt"

func coprime(a int, b int) int {

	for i := 2; i <= a; i++ {
		if a % i == 0 && b % i == 0 {
			return -1
		}
	}

	return 1
}


func main() {

	var num1, num2, res int
	
	fmt.Scan(&num1)
	fmt.Scan(&num2)

	if num1 > num2 {
		res = coprime(num1, num2)
	} else {
		res = coprime(num2, num1)
	}

	if res == 1 {
		fmt.Println("Numbers are coprime")
	} else {
		fmt.Println("Numbers are not coprime")
	}
}
