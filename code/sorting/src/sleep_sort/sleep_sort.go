/* Part of Cosmos by OpenGenus Foundation */
package main

import "fmt"
import "runtime"
import "time"

func sleepNumber(number int, results chan<- int) {
	time.Sleep(time.Duration(number) * time.Second)
	results <- number
}

func sleepSort(data []int) {
	results := make(chan int, len(data))
	for _, v := range data {
		go sleepNumber(v, results)
	}

	for i, _ := range data {
		data[i] = <-results
	}
	close(results)
}

func main() {
	data := []int{8, 2, 4, 5, 6, 7, 1, 4, 10}
	runtime.GOMAXPROCS(len(data))
	fmt.Println("Before sorting", data)
	sleepSort(data)
	fmt.Println("After sorting", data)
}
