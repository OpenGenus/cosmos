// Part of Cosmos by OpenGenus Foundation

package main

import (
	"fmt"
)

type Node struct {
	key  interface{}
	next *Node
	prev *Node
}

type DoubleLinkedList struct {
	head *Node
	tail *Node
}

func (l *DoubleLinkedList) Insert(key interface{}) {
	newNode := &Node{key, l.head, nil}
	if l.head != nil {
		l.head.prev = newNode
	}
	l.head = newNode
}

func (l *DoubleLinkedList) Delete(key interface{}) {
	temp := l.head
	prev := &Node{}
	if temp != nil && temp.key == key {
		l.head = temp.next
		temp.next.prev = l.head
		return
	}
	for temp != nil && temp.key != key {
		prev = temp
		temp = temp.next
	}
	if temp == nil {
		return
	}
	prev.next = temp.next
}

func (l *DoubleLinkedList) Show() {
	list := l.head
	for list != nil {
		fmt.Printf("%+v <-> ", list.key)
		list = list.next
	}
	fmt.Println()
}

func main() {
	l := DoubleLinkedList{}
	l.Insert(1)
	l.Insert(2)
	l.Insert(3)
	l.Insert(4)
	l.Insert(5)
	l.Insert(6)
	l.Delete(1)
	l.Delete(9)
	l.Show()
}
