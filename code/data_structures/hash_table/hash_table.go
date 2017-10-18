package main

import (
	"errors"
	"fmt"
	"container/list"
)

var (
	ErrKeyNotFound = errors.New("key not found")
)

type Item struct {
	key int 
	value interface{}
}

type Hashtable struct{
	size int
	data []*list.List
}

func (h *Hashtable) Insert(key int, value interface{}) {
	item := &Item{key: key, value: value}
	hashed := key % h.size
	l :=	h.data[hashed]
	if l == nil {
		l = list.New()
		h.data[hashed] = l
	}
	for elem := l.Front(); elem != nil; elem = elem.Next() {
		// If found the element -> update
		i, _ := elem.Value.(*Item)
		if i.key == item.key {
			i.value = value
			return
		}
	}
	l.PushFront(item)
	return
}

func (h *Hashtable) Get(key int) (interface{}, error) {
	hashed := key % h.size
	l := h.data[hashed]
	if l == nil {
		return nil, ErrKeyNotFound
	}
	for elem := l.Front(); elem != nil; elem = elem.Next() {
		item := elem.Value.(*Item)
		if item.key == key {
			return item.value, nil
		}
	}

	return nil, ErrKeyNotFound
}

func NewHashtable(size int) *Hashtable {
	return &Hashtable{
		size: size,
		data: make([]*list.List, size),
	}
}

func main() {
	h := NewHashtable(10)
	h.Insert(1, "abc")
	value, _ := h.Get(1)
	fmt.Printf("h[1] = %s\n", value) // Print "abc"

	h.Insert(11, "def")
	value, _ = h.Get(11)
	fmt.Printf("h[11] = %s\n", value) // Print "def"

	value, err := h.Get(2)
	fmt.Printf("Err = %#v\n", err) // ErrKeyNotFound
}
