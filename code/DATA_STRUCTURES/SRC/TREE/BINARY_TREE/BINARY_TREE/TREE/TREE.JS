/* Part of Cosmos by OpenGenus Foundation */

/*Binary Search Tree!!
*
* Nodes that will go on the Binary Tree.
* They consist of the data in them, the node to the left, the node
* to the right, and the parent from which they came from.
*
* A binary tree is a data structure in which an element
* has two successors(children). The left child is usually
* smaller than the parent, and the right child is usually
* bigger.
*/

// Node in the tree
function Node(val) {
  this.value = val;
  this.left = null;
  this.right = null;
}

// Search the tree for a value
Node.prototype.search = function(val) {
  if (this.value == val) {
    return this;
  } else if (val < this.value && this.left != null) {
    return this.left.search(val);
  } else if (val > this.value && this.right != null) {
    return this.right.search(val);
  }
  return null;
}

// Visit a node
Node.prototype.visit = function() {
  // Recursively go left
  if (this.left != null) {
    this.left.visit();
  }
  // Print out value
  console.log(this.value);
  // Recursively go right
  if (this.right != null) {
    this.right.visit();
  }
}

// Add a node
Node.prototype.addNode = function(n) {
  if (n.value < this.value) {
    if (this.left == null) {
      this.left = n;
    } else {
      this.left.addNode(n)
    }
  } else if (n.value > this.value) {
    if (this.right == null) {
      this.right = n;
    } else {
      this.right.addNode(n);
    }
  }
}

function Tree() {
  // Just store the root
  this.root = null;
}

// Inorder traversal
Tree.prototype.traverse = function() {
  this.root.visit();
}

// Start by searching the root
Tree.prototype.search = function(val) {
  var found = this.root.search(val);
  if(found === null)
  {
    console.log(val + " not found");
  }
  else{
    console.log("Found:"+found.value);
  }
}

// Add a new value to the tree
Tree.prototype.addValue = function(val) {
  var n = new Node(val);
  if (this.root == null) {
    this.root = n;
  } else {
    this.root.addNode(n);
  }
}

//Implementation of BST
var bst = new Tree();
bst.addValue(6);
bst.addValue(3);
bst.addValue(9);
bst.addValue(2);
bst.addValue(8);
bst.addValue(4);
bst.traverse();
bst.search(8);
