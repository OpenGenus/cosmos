package main

import (
    "fmt"
)

func main() {
    var n int
    fmt.Println("Please enter the lenght of the array:")
    fmt.Scan(&n)
    X := make([]int, n)

    fmt.Println("Now, enter the elements X0 X1 ... Xn-1")

     for i := 0; i < n; i++ {
        fmt.Scanln(&X[i])
    }

    fmt.Printf("Unsorted array: %v\n", X)
    fmt.Printf("Sorted array: %v\n", BubbleSort(X))
    
}

func BubbleSort(arr[] int)[]int {
  for i:=1; i< len(arr); i++ {
    for j:=0; j < len(arr)-i; j++ {
      if (arr[j] > arr[j+1]) {
        arr[j], arr[j+1] = arr[j+1], arr[j]
      }
    }
  }
  return arr
}