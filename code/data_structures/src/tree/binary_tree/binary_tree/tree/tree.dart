// Binary Search Trees

import 'dart:math';

class BST {
  BST([this.key, this.left, this.right]);
  int? key;
  BST? left;
  BST? right;

  void insert(int key) {
    if (this.key == null) {
      this.key = key;
    }
    if (key == this.key) {
      return;
    }
    if (key < this.key!.toInt()) {
      if (this.left == null) {
        this.left = BST(key);
      }
      this.left!.insert(key);
    }
    if (key > this.key!.toInt()) {
      if (this.right == null) {
        this.right = BST(key);
      }
      this.right!.insert(key);
    }
  }
}

int? toSearch(int key, BST? bst) {
  if (bst?.key != null) {
    if (key == bst!.key) {
      return bst.key;
    } else {
      int? foundNode = toSearch(key, bst.left);
      if (foundNode == null) {
        foundNode = toSearch(key, bst.right);
      }
      return foundNode;
    }
  } else {
    return null;
  }
}

void preOrderPrint(BST? bst) {
  if (bst == null) {
    return;
  }
  print(bst.key);
  preOrderPrint(bst.left);
  preOrderPrint(bst.right);
}

void inOrderPrint(BST? bst) {
  if (bst == null) {
    return;
  }
  inOrderPrint(bst.left);
  print(bst.key);
  inOrderPrint(bst.right);
}

void postOrderPrint(BST? bst) {
  if (bst == null) {
    return;
  }
  preOrderPrint(bst.left);
  preOrderPrint(bst.right);
  print(bst.key);
}

List<int> randIntList({required int length, int range = 10}) {
  Random rand = Random();
  List<int> result = [for (var i = 0; i < length; i++) rand.nextInt(range)];
  return result;
}

void lines() {
  print("-------------------------------------------------");
}

int main() {
  try {
    final BST bst = BST();
    final arr = randIntList(length: 10, range: 20);
    arr.forEach((key) => bst.insert(key));
    lines();
    print("Pre-order Traversal");
    lines();
    preOrderPrint(bst);
    lines();
    print("In-order Traversal");
    lines();
    inOrderPrint(bst);
    lines();
    print("Post-order Traversal");
    lines();
    postOrderPrint(bst);
    lines();
    arr.add(404);
    print("Array elements: $arr");
    lines();
    arr.forEach((key) => print("Element $key in BST: ${toSearch(key, bst)}"));
  } catch (e) {
    print(e);
  }
  return 0;
}
