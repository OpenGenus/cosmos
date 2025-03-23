// Part of Cosmos by OpenGenus Foundation
package main

import "fmt"

type Queue []int

func (s *Queue) Push(v int) Queue {
	return append(*s, v)
}

func (s *Queue) Pop() Queue {
	length := len(*s)
	if length != 0 {
		return (*s)[1:]
	}
	return *s
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

func main() {
	queue := Queue{}
	fmt.Printf("Current Queue is %s, Is Queue empty ? %v \n", queue, queue.Empty())
	fmt.Printf("Try to push 30 into Queue\n")
	queue = queue.Push(30)
	fmt.Printf("Current Queue is %v, top value is %v\n", queue, queue.Top())
	fmt.Printf("Try to push 12 into Queue\n")
	queue = queue.Push(12)
	fmt.Printf("Try to push 34 into Queue\n")
	queue = queue.Push(34)
	fmt.Printf("Current Queue is %v, top value is %v\n", queue, queue.Top())
	fmt.Printf("Current Queue is %v, Is Queue empty ? %v \n", queue, queue.Empty())
	queue = queue.Pop()
	fmt.Printf("Current Queue is %v, top value is %v\n", queue, queue.Top())
	queue = queue.Pop()
	queue = queue.Pop()
	fmt.Printf("Current Queue is %v, Is Queue empty ? %v\n", queue, queue.Empty())
}
