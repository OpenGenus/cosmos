// Part of Cosmos by OpenGenus Foundation
package main

/*
Expect output
Current Stack is [], Is Stack empty ? true
Try to push 30 into Stack
Try to push 12 into Stack
Try to push 34 into Stack
Try to push 2 into Stack
Try to push 17 into Stack
Try to push 88 into Stack
Reverse Stack
30 12 34 2 17 88

*/
import "fmt"

type Stack []int

func (s *Stack) Push(v int) {
	*s = append(*s, v)
}

func (s *Stack) Pop() {
	length := len(*s)
	if length != 0 {
		(*s) = (*s)[:length-1]
	}
}

func (s *Stack) Top() int {
	return (*s)[len(*s)-1]
}

func (s *Stack) Empty() bool {
	if len(*s) == 0 {
		return true
	}

	return false
}

func (s *Stack) Reverse() {
	for i, j := 0, len(*s)-1; i < j; i, j = i+1, j-1 {
		(*s)[i], (*s)[j] = (*s)[j], (*s)[i]
	}
}

func main() {
	stack := Stack{}
	fmt.Printf("Current Stack is %s, Is Stack empty ? %v \n", stack, stack.Empty())
	fmt.Printf("Try to push 30 into Stack\n")
	stack.Push(30)
	fmt.Printf("Try to push 12 into Stack\n")
	stack.Push(12)
	fmt.Printf("Try to push 34 into Stack\n")
	stack.Push(34)
	fmt.Printf("Try to push 2 into Stack\n")
	stack.Push(2)
	fmt.Printf("Try to push 17 into Stack\n")
	stack.Push(17)
	fmt.Printf("Try to push 88 into Stack\n")
	stack.Push(88)

	fmt.Println("Reverse Stack")
	stack.Reverse()
	for !stack.Empty() {
		fmt.Printf("%d ", stack.Top())
		stack.Pop()
	}
	fmt.Printf("\n")
}
