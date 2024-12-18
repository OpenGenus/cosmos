'use strict';

/**
 * Creates a binomial heap.
 *
 * @constructor
 * @param {function} customCompare An optional custom node comparison
 * function.
 */
var BinomialHeap = function (customCompare) {
  this.head = undefined;
  this.nodeCount = 0;

  if (customCompare) {
    this.compare = customCompare;
  }
};

/**
 * Clears the heap's data, making it an empty heap.
 */
BinomialHeap.prototype.clear = function () {
  this.head = undefined;
  this.nodeCount = 0;
};

/**
 * Extracts and returns the minimum node from the heap.
 *
 * @return {Node} node The heap's minimum node or undefined if the heap is
 * empty.
 */
BinomialHeap.prototype.extractMinimum = function () {
  if (!this.head) {
    return undefined;
  }

  var min = this.head;
  var minPrev;
  var next = min.sibling;
  var nextPrev = min;

  while (next) {
    if (this.compare(next, min) < 0) {
      min = next;
      minPrev = nextPrev;
    }
    nextPrev = next;
    next = next.sibling;
  }

  removeTreeRoot(this, min, minPrev);
  this.nodeCount--;

  return min;
};

/**
 * Returns the minimum node from the heap.
 *
 * @return {Node} node The heap's minimum node or undefined if the heap is
 * empty.
 */
BinomialHeap.prototype.findMinimum = function () {
  if (typeof this.head === 'undefined') {
    return undefined;
  }

  var min = this.head;
  var next = min.sibling;

  while (next) {
    if (this.compare(next, min) < 0) {
      min = next;
    }
    next = next.sibling;
  }

  return min;
};

/**
 * Inserts a new key-value pair into the heap.
 *
 * @param {Object} key The key to insert.
 * @param {Object} value The value to insert.
 * @return {Node} node The inserted node.
 */
BinomialHeap.prototype.insert = function (key, value) {
  var tempHeap = new BinomialHeap();
  var newNode = new Node(key, value);
  tempHeap.head = newNode;
  tempHeap.nodeCount++;
  this.union(tempHeap);
  return newNode;
};

/**
 * @return {boolean} Whether the heap is empty.
 */
BinomialHeap.prototype.isEmpty = function () {
  return !this.head;
};

/**
 * @return {number} The size of the heap.
 */
BinomialHeap.prototype.size = function () {
  return this.nodeCount;
};

/**
 * Joins another heap to this one.
 *
 * @param {BinomialHeap} otherHeap The other heap.
 */
BinomialHeap.prototype.union = function (heap) {
  this.nodeCount += heap.nodeCount;

  var newHead = mergeHeaps(this, heap);

  this.head = undefined;
  heap.head = undefined;

  if (!newHead) {
    return undefined;
  }

  var prev;
  var curr = newHead;
  var next = newHead.sibling;

  while (next) {
    if (curr.degree !== next.degree ||
        (next.sibling && next.sibling.degree === curr.degree)) {
      prev = curr;
      curr = next;
    } else if (this.compare(curr, next) < 0) {
      curr.sibling = next.sibling;
      linkTrees(curr, next);
    } else {
      if (typeof prev === 'undefined') {
        newHead = next;
      } else {
        prev.sibling = next;
      }

      linkTrees(next, curr);
      curr = next;
    }

    next = curr.sibling;
  }

  this.head = newHead;
};

/**
 * Compares two nodes with each other.
 *
 * @private
 * @param {Object} a The first key to compare.
 * @param {Object} b The second key to compare.
 * @return {number} -1, 0 or 1 if a < b, a == b or a > b respectively.
 */
BinomialHeap.prototype.compare = function (a, b) {
  if (a.key > b.key) {
    return 1;
  }
  if (a.key < b.key) {
    return -1;
  }
  return 0;
};

/**
 * Merges two heaps together.
 *
 * @private
 * @param {Node} a The head of the first heap to merge.
 * @param {Node} b The head of the second heap to merge.
 * @return {Node} The head of the merged heap.
 */
function mergeHeaps(a, b) {
  if (typeof a.head === 'undefined') {
    return b.head;
  }
  if (typeof b.head === 'undefined') {
    return a.head;
  }

  var head;
  var aNext = a.head;
  var bNext = b.head;

  if (a.head.degree <= b.head.degree) {
    head = a.head;
    aNext = aNext.sibling;
  } else {
    head = b.head;
    bNext = bNext.sibling;
  }

  var tail = head;

  while (aNext && bNext) {
    if (aNext.degree <= bNext.degree) {
      tail.sibling = aNext;
      aNext = aNext.sibling;
    } else {
      tail.sibling = bNext;
      bNext = bNext.sibling;
    }

    tail = tail.sibling;
  }

  tail.sibling = aNext ? aNext : bNext;

  return head;
}

/**
 * Link two binomial trees of the same order.
 *
 * @private
 * @param {Node} minNodeTree The head of the first tree to link.
 * @param {Node} other The head of the second tree to link.
 */
function linkTrees(minNodeTree, other) {
  other.parent = minNodeTree;
  other.sibling = minNodeTree.child;
  minNodeTree.child = other;
  minNodeTree.degree++;
}

/**
 * Link two binomial trees of the same order.
 *
 * @private
 * @param {Node} minNodeTree The head of the first tree to link.
 * @param {Node} other The head of the second tree to link.
 */
function removeTreeRoot(heap, root, prev) {
  // Remove root from the heap
  if (root === heap.head) {
    heap.head = root.sibling;
  } else {
    prev.sibling = root.sibling;
  }

  // Reverse the order of root's children and make a new heap
  var newHead;
  var child = root.child;
  while (child) {
    var next = child.sibling;
    child.sibling = newHead;
    child.parent = undefined;
    newHead = child;
    child = next;
  }
  var newHeap = new BinomialHeap();
  newHeap.head = newHead;

  heap.union(newHeap);
}

/**
 * Creates a Binomial Heap node.
 *
 * @constructor
 * @param {Object} key The key of the new node.
 * @param {Object} value The value of the new node.
 */
function Node(key, value) {
  this.key = key;
  this.value = value;
  this.degree = 0;
  this.parent = undefined;
  this.child = undefined;
  this.sibling = undefined;
}

module.exports = BinomialHeap;