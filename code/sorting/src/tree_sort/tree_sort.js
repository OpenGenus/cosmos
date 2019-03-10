// Part of Cosmos by OpenGenus Foundation
var BinarySearchTree = function(value) {
  var instance = Object.create(BinarySearchTree.prototype);

  instance.value = value;
  // a BST where all values are higher than than the current value.
  instance.right = undefined;
  // a binary search tree (BST) where all values are lower than than the current value.
  instance.left = undefined;

  return instance;
};

BinarySearchTree.prototype.insert = function(value) {
  // accepts a value and places in the tree in the correct position.
  var node = BinarySearchTree(value);

  function recurse(bst) {
    if (bst.value > value && bst.left === undefined) {
      bst.left = node;
    } else if (bst.value > value) {
      recurse(bst.left);
    } else if (bst.value < value && bst.right === undefined) {
      bst.right = node;
    } else if (bst.value < value) {
      recurse(bst.right);
    }
  }

  recurse(this);
};

BinarySearchTree.prototype.contains = function(value) {
  var doesContain = false;
  //accepts a value and returns a boolean reflecting whether or not the value is contained in the tree.
  function recurse(bst) {
    if (bst.value === value) {
      doesContain = true;
    } else if (bst.left !== undefined && value < bst.value) {
      recurse(bst.left);
    } else if (bst.right !== undefined && value > bst.value) {
      recurse(bst.right);
    }
  }

  recurse(this);
  return doesContain;
};

BinarySearchTree.prototype.depthFirstLog = function(callback) {
  //accepts a callback and executes it on every value contained in the tree.
  function recurse(bst) {
    callback.call(bst, bst.value);

    if (bst.left !== undefined) {
      recurse(bst.left);
    }

    if (bst.right !== undefined) {
      recurse(bst.right);
    }
  }

  recurse(this);
};
