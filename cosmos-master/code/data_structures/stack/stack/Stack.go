// Part of Cosmos by OpenGenus Foundation
package main

import "fmt"

type Stack []int

func (s *Stack) Push(v int) Stack {
	return append(*s, v)
}

func (s *Stack) Pop() Stack {
	length := len(*s)
	if length != 0 {
		return (*s)[:length-1]
	}
	return *s
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

func main() {
	stack := Stack{}
	fmt.Printf("Current Stack is %s, Is Stack empty ? %v \n", stack, stack.Empty())
	fmt.Printf("Try to push 30 into Stack\n")
	stack = stack.Push(30)
	fmt.Printf("Current Stack is %v, top value is %v\n", stack, stack.Top())
	fmt.Printf("Try to push 12 into Stack\n")
	stack = stack.Push(12)
	fmt.Printf("Try to push 34 into Stack\n")
	stack = stack.Push(34)
	fmt.Printf("Current Stack is %v, top value is %v\n", stack, stack.Top())
	fmt.Printf("Current Stack is %v, Is Stack empty ? %v \n", stack, stack.Empty())
	stack = stack.Pop()
	fmt.Printf("Current Stack is %v, top value is %v\n", stack, stack.Top())
	stack = stack.Pop()
	stack = stack.Pop()
	fmt.Printf("Current Stack is %v, Is Stack empty ? %v\n", stack, stack.Empty())
}
