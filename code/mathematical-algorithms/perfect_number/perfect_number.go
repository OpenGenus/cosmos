// Part of Cosmos by OpenGenus Foundation
package main

import "fmt"

func isPerfect(n int) bool {
    sumOfDivisors := (-n) // Comensate addition of n (last divisor of n)

    for i := 1; i*i < n; i++ { // O(sqrt n) complexity
        if n % i == 0 {
            if (n / i == i) {
                sumOfDivisors += i
            } else {
                sumOfDivisors += i
                sumOfDivisors += (n / i)
            }
        }
    }

    return (sumOfDivisors == n)
}

func getPerfectNumbersBetween(low int, high int) []int {
    list := make([]int, 0)

    for i := max(low, 2); i <= high; i++ {
        if isPerfect(i) {
            list = append(list, i)
        }
    }

    return list
}

func max(a int, b int) int {
    if a > b {
        return a
    }
    return b
}

func main() {
    fmt.Print("Listing perfect numbers from 0 to 10000:\n")
    list := getPerfectNumbersBetween(0, 10000)
    for i := 0; i < len(list); i++ {
        fmt.Print(list[i], "\n")
    }
}