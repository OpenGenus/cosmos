package main

import "fmt"
// Part of Cosmos by OpenGenus Foundation
func SieveOfEratosthenes(n int) []int {
	//Create an array of Boolean values indexed by
    //integers 2 to n, initially all set to true.
	integers := make([]bool, n+1)
	for i := 2; i < n+1; i++ {
		integers[i] = true
	}

	for i := 2; i*i <= n; i++ {
		if integers[i] == true {
			//Check all multiples of i
				for j := i * 2; j <= n; j += i {
					integers[j] = false
				}
		}
	}

		//Return all unchanged numbers (prime numbers) <= n
		var primes []int
		for i := 2; i <= n; i++ {
			if integers[i] == true {
				primes = append(primes, i)
			}
		}
		return primes
}
