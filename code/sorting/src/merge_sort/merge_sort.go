package main

import (
    "fmt"
)

func main() {
    A := []int{3, 5, 1, 6, 1, 7, 2, 4, 5}
    fmt.Println(sort(A))
}

// top-down approach
func sort(A []int) []int {
    if len(A) <= 1 {
        return A
    }

    left, right := split(A)
    left = sort(left)
    right = sort(right)
    return merge(left, right)
}

// split array into two
func split(A []int) ([]int, []int) {
    return A[0:len(A) / 2], A[len(A) / 2:]
}

// assumes that A and B are sorted
func merge(A, B []int) []int {
    arr := make([]int, len(A) + len(B))

    // index j for A, k for B
    j, k := 0, 0

    for i := 0; i < len(arr); i++ {
        // fix for index out of range without using sentinel
        if j >= len(A) {
            arr[i] = B[k]
            k++
            continue
        } else if k >= len(B) {
            arr[i] = A[j]
            j++
            continue
        }
        // default loop condition
        if A[j] > B[k] {
            arr[i] = B[k]
            k++
        } else {
            arr[i] = A[j]
            j++
        }
    }

    return arr
}
