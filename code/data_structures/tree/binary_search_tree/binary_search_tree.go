package main

// Part of Cosmos by OpenGenus Foundation
import "fmt"

type Node struct {
	val    int
	lchild *Node
	rchild *Node
}

func (ref *Node) insert(newNode *Node) {

	if ref.val == newNode.val {
		return
	}

	if ref.val < newNode.val {
		if ref.rchild == nil {
			ref.rchild = newNode
		} else {
			ref.rchild.insert(newNode)
		}
	} else {
		if ref.lchild == nil {
			ref.lchild = newNode
		} else {
			ref.lchild.insert(newNode)
		}
	}
}

func (ref *Node) inOrder(fn func(n *Node)) {

	if ref.lchild != nil {
		ref.lchild.inOrder(fn)
	}

	fn(ref)

	if ref.rchild != nil {
		ref.rchild.inOrder(fn)
	}

}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func getHeight(node *Node) int {
	if node == nil {
		return 0
	}

	return max(getHeight(node.lchild), getHeight(node.rchild)) + 1
}

type BSTree struct {
	ref    *Node
	length int
}

func (BSTree *BSTree) insert(value int) {
	node := &Node{val: value}

	if BSTree.ref == nil {
		BSTree.ref = node
	} else {
		BSTree.ref.insert(node)
	}
}

func (BSTree *BSTree) inorderPrint() {
	BSTree.ref.inOrder(func(node *Node) {
		fmt.Println(node.val)
	})
}

func (BSTree *BSTree) height() int {
	return getHeight(BSTree.ref)
}

func main() {

	tree := new(BSTree)
	tree.insert(1)
	tree.insert(0)
	tree.insert(20)
	tree.insert(4)
	tree.insert(5)
	tree.insert(6)
	fmt.Println("Height ", tree.height())

	tree.inorderPrint()

}
