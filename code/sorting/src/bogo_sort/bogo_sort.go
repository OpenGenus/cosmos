package main

import (
  "fmt"
  "sort"
  "math/rand"
  "time"
)

func shuffle(arr []int) []int {
  for i := range arr {
    j := rand.Intn(i + 1)
    arr[i], arr[j] = arr[j], arr[i]
  }
  return arr
}

func bogoSort(array []int) []int {
  for {
    if sort.IntsAreSorted(array) {
      return array
    }
  array = shuffle(array[:])
  }
}

func main() {
  rand.Seed(time.Now().UnixNano())
  var array = []int{1,5,8,2,6,9}
  sorted := bogoSort(array)
  fmt.Println("Sorted sequence is:", sorted)
}
