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

void inOrderPrint(BST? bst) {
  if (bst == null) {
    return;
  }
  inOrderPrint(bst.left);
  print(bst.key);
  inOrderPrint(bst.right);
}

List<int> randIntList({required int length, int range = 10}) {
  Random rand = Random();
  List<int> result = [for (var i = 0; i < length; i++) rand.nextInt(range)];
  return result;
}

int main() {
  try {
    final arr = randIntList(length: 10, range: 20);
    final BST bst = BST();
    arr.forEach((key) => bst.insert(key));
    inOrderPrint(bst);

    arr.add(404);
    print(arr);
    arr.forEach((key) => print("Element $key in BST: ${toSearch(key, bst)}"));
  } catch (e) {
    print(e);
  }
  return 0;
}
