package main

import "fmt"

// TrieNode has a value and a pointer to another TrieNode
type TrieNode struct {
	children map[rune]*TrieNode
	value    interface{}
}

// New allocates and returns a new *TrieNode.
func New() *TrieNode {
	return &TrieNode{
		children: make(map[rune]*TrieNode),
	}
}

// Contains returns true trie contains text otherwise return false
func (trie *TrieNode) Contains(key string) bool {
	node := trie
	for _, ch := range key {
		node = node.children[ch]
		if node == nil {
			return false
		}

	}
	return node.value != nil
}

func (trie *TrieNode) Insert(key string, value int) bool {
	node := trie
	for _, ch := range key {
		child, _ := node.children[ch]

		if child == nil {
			child = New()
			node.children[ch] = child
		}

		node = child
	}

	isNewVal := node.value == nil
	node.value = value

	return isNewVal
}

// PathTrie node and the part string key of the child the path descends into.
type nodeStr struct {
	node *TrieNode
	part rune
}

func (trie *TrieNode) Delete(key string) bool {
	var path []nodeStr // record ancestors to check later
	node := trie
	for _, ch := range key {
		path = append(path, nodeStr{part: ch, node: node})
		node = node.children[ch]
		if node == nil {
			// node does not exist
			return false
		}
	}

	// delete the node value
	node.value = nil

	// if leaf, remove it from its parent's children map. Repeat for ancestor path.
	if len(node.children) == 0 {
		// iterate backwards over path
		for i := len(path) - 1; i >= 0; i-- {
			parent := path[i].node
			part := path[i].part
			delete(parent.children, part)
			if parent.value != nil || !(len(parent.children) == 0) {
				// parent has a value or has other children, stop
				break
			}
		}
	}

	return true
}

func main() {
	keys := []string{"cat", "case", "deaf", "dear", "a", "an", "the"}
	tr := New()

	for i, key := range keys {
		tr.Insert(key, i)
	}

	tr.Delete("dear")
	var contains string

	if tr.Contains("dear") {
		contains = "contains"
	} else {
		contains = "does not contain"
	}
	fmt.Printf("Trie %v %v\n", contains, "dear")
	if tr.Contains("case") {
		contains = "contains"
	} else {
		contains = "does not contain"
	}
	fmt.Printf("Trie %v %v\n", contains, "case")
}
