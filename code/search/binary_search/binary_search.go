package main

import "fmt"

func binary_search(array []int, begin int, end int, n int) int {
    if  end >= begin {
        mid := begin + (end - begin)/2
        if array[mid] == n {
            return mid
        } else if array[mid] > n {
            return binary_search(array,begin,mid-1,n)
        } else {
            return binary_search(array,mid+1,end,n)
        }
    } else {
        return -1
    }
}

func main() {
    array := []int{1,2,3,4,5,6,7,8,9,10}
    index := binary_search(array,0,len(array)-1,9)
    fmt.Println(index)
}
