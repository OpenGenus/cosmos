// Part of Cosmos by OpenGenus Foundation
package main

/*
Exptected output:
Current Queue is [], Is Queue empty ? true
Try to push 30 into Queue
Try to push 12 into Queue
Try to push 34 into Queue
Try to push 2 into Queue
Try to push 17 into Queue
Try to push 88 into Queue
Reverse Queue
88 17 2 34 12 30


*/
import "fmt"

type Queue []int

func (q *Queue) Push(v int) {
	*q = append(*q, v)
}

func (q *Queue) Pop() {
	length := len(*q)
	if length != 0 {
		(*q) = (*q)[1:]
	}
}

func (q *Queue) Top() int {
	return (*q)[0]
}

func (q *Queue) Empty() bool {
	if len(*q) == 0 {
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
