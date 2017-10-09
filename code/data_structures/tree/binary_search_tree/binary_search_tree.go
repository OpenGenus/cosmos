package main
 +
 +import "fmt"
 +
 +type Node struct {
 +	val   int
 +	lchild  *Node
 +	rchild *Node
 +}
 +
 +func (ref *Node) insert(newNode *Node) {
 +
 +	if ref.val == newNode.val {
 +		return
 +	}
 +
 +	
 +	if ref.val < newNode.val {
 +		if ref.rchild == nil {
 +			ref.rchild = newNode
 +		} else {
 +			ref.rchild.insert(newNode)
 +		}
 +	} else {
 +		if ref.lchild == nil {
 +			ref.lchild = newNode
 +		} else {
 +			ref.lchild.insert(newNode)
 +		}
 +	}
 +}
 +
 +func (ref *Node) inOrder(fn func(n *Node)) {
 +
 +	if ref.lchild != nil {
 +		ref.lchild.inOrder(fn)
 +	}
 +
 +	fn(ref)
 +
 +	if ref.rchild != nil {
 +		ref.rchild.inOrder(fn)
 +	}
 +
 +}
 +
 +type BSTree struct {
 +	ref   *Node
 +	length int
 +}
 +
 +func (BSTree *BSTree) insert(value int) {
 +	node := &Node{val: value}
 +	BSTree.length++
 +
 +	if BSTree.ref == nil {
 +		BSTree.ref = node
 +	} else {
 +		BSTree.ref.insert(node)
 +	}
 +}
 +
 +func (BSTree *BSTree) inorderPrint() {
 +	BSTree.ref.inOrder(func(node *Node) {
 +		fmt.Println(node.val)
 +	})
 +}
 +
 +func main() {
 +
 +	tree := new(BSTree)
 +	tree.insert(1)
 +	tree.insert(0)
 +	tree.insert(20)
 +	tree.insert(4)
 +	tree.insert(5)
 +	tree.insert(6)
 +
 +	tree.inorderPrint()
 +
 +}
