package main

import "fmt"

// Part of Cosmos by OpenGenus Foundation

/**************************************
 * Structures
 **************************************/

// Define binary tree structure
//
//    - data  :   the value in the tree
//    - right :   the sub-tree of greater or equal values
//    - left  :   the sub-tree of lesser values
type Tree struct {
  data int
  right *Tree
  left *Tree
}

// Create a Tree by initializing its subtree to nil
// and setting it's value.
func createTree(value int) *Tree {
  var tree = Tree{}
  tree.data = value
  tree.right = nil
  tree.left = nil
  return &tree
}

// Insert the given value in the tree.
//
// The tree is traveled until an empty sub-tree is found:
//    If the value is lesser than the one hold by the current node,
//    try to insert it to the left.
//    If the value is greater or equal than the one hold by the current node,
//    try to insert it to the right.
// The value is inserted by creating a new sub-tree.
func (t *Tree) insert(value int) *Tree {
  if value < t.data {
    if t.left == nil {
      t.left = createTree(value)
    } else {
      t.left.insert(value)
    }
  } else {
    if t.right == nil {
      t.right = createTree(value)
    } else {
      t.right.insert(value)
    }
  }
  return t
}

// Apply the given function to each  value in the tree
// from left to right, i.e. from the lesser one to the greater one.
func (t *Tree) forEach(fn func(int)) {
  if t.left != nil {
    t.left.forEach(fn)
  }
  fn(t.data)
  if t.right != nil {
    t.right.forEach(fn)
  }
}

/**************************************
 * Algorithm
 **************************************/

// Perform a binary tree sort of the given array
// and return the created tree.
func binaryTreeSort(array []int) *Tree {
  tree := createTree(array[0])
  for _, node := range array[1:] {
    tree.insert(node)
  }
  return tree
}

/**************************************
 * Tests
 **************************************/

// Test the binary tree sort on the given array:
//
//    [1, -6, 8, 3, 10, 3, 21]
//
// Should output: -6 1 3 3 8 10 21 
//
// NOTE: this will only display the values in the tree by traveling
//       it from left to right.
//       If you want to fill an array with the values,
//       just pass a function that fills it to tree.forEach().
func main() {
  var array = [...]int{1,-6,8,3,10,3,21}
  tree := binaryTreeSort(array[:])
  tree.forEach(func(value int) {
    fmt.Print(value, " ")
  })
}