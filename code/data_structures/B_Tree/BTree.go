package main

import "fmt"

type Node struct {
	val   int
	lchild  *Node
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

type BTree struct {
	ref   *Node
	length int
}

func (BTree *BTree) insert(value int) {
	node := &Node{val: value}
	BTree.length++

	if BTree.ref == nil {
		BTree.ref = node
	} else {
		BTree.ref.insert(node)
	}
}

func (BTree *BTree) inorderPrint() {
	BTree.ref.inOrder(func(node *Node) {
		fmt.Println(node.val)
	})
}

func main() {

	tree := new(BTree)
	tree.insert(1)
	tree.insert(0)
	tree.insert(20)
	tree.insert(4)
	tree.insert(5)
	tree.insert(6)

	tree.inorderPrint()

}
