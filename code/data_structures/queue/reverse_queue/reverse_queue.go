// Part of Cosmos by OpenGenus Foundation
package main

import "fmt"

type Queue []int

func (s *Queue) Push(v int) {
	*s = append(*s, v)
}

func (s *Queue) Pop() {
	length := len(*s)
	if length != 0 {
		(*s) = (*s)[1:]
	}
}

func (s *Queue) Top() int {
	return (*s)[0]
}

func (s *Queue) Empty() bool {
	if len(*s) == 0 {
		return true
	}

	return false
}

func (q *Queue) Reverse() {
	for i, j := 0, len(*q)-1; i < j; i, j = i+1, j-1 {
		(*q)[i], (*q)[j] = (*q)[j], (*q)[i]
	}
}

func main() {
	queue := Queue{}
	fmt.Printf("Current Queue is %s, Is Queue empty ? %v \n", queue, queue.Empty())
	fmt.Printf("Try to push 30 into Queue\n")
	queue.Push(30)
	fmt.Printf("Try to push 12 into Queue\n")
	queue.Push(12)
	fmt.Printf("Try to push 34 into Queue\n")
	queue.Push(34)
	fmt.Printf("Try to push 2 into Queue\n")
	queue.Push(2)
	fmt.Printf("Try to push 17 into Queue\n")
	queue.Push(17)
	fmt.Printf("Try to push 88 into Queue\n")
	queue.Push(88)

	fmt.Println("Reverse Queue")
	queue.Reverse()
	for !queue.Empty() {
		fmt.Printf("%d ", queue.Top())
		queue.Pop()
	}
	fmt.Printf("\n")

}
