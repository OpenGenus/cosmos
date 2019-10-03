package main

import (
      "fmt"
)

// Get all prime factors of a given number n
func PrimeFactors(n int) (pfs []int) {
      // Get the number of 2s that divide n
      for n%2 == 0 {
              pfs = append(pfs, 2)
              n = n / 2
      }

      // n must be odd at this point. so we can skip one element
      // (note i = i + 2)
      for i := 3; i*i <= n; i = i + 2 {
              // while i divides n, append i and divide n
              for n%i == 0 {
                      pfs = append(pfs, i)
                      n = n / i
              }
      }

      // This condition is to handle the case when n is a prime number
      // greater than 2
      if n > 2 {
              pfs = append(pfs, n)
      }

      return
}

// return p^i
func Power(p, i int) int {
      result := 1
      for j := 0; j < i; j++ {
              result *= p
      }
      return result
}

// formula comes from https://math.stackexchange.com/a/22723
func SumOfProperDivisors(n int) int {
      pfs := PrimeFactors(n)

      // key: prime
      // value: prime exponents
      m := make(map[int]int)
      for _, prime := range pfs {
              _, ok := m[prime]
              if ok {
                      m[prime] += 1
              } else {
                      m[prime] = 1
              }
      }

      sumOfAllFactors := 1
      for prime, exponents := range m {
              sumOfAllFactors *= (Power(prime, exponents+1) - 1) / (prime - 1)
      }
      return sumOfAllFactors - n
}

func AmicableNumbersUnder10000() (amicables []int) {
      for i := 3; i < 10000; i++ {
              s := SumOfProperDivisors(i)
              if s == i {
                      continue
              }
              if SumOfProperDivisors(s) == i {
                      amicables = append(amicables, i)
              }
      }
      return
}

func main() {
      amicables := AmicableNumbersUnder10000()
      fmt.Println(amicables)

      sum := 0
      for i := 0; i < len(amicables); i++ {
              sum += amicables[i]
      }
      fmt.Println(sum)
}
