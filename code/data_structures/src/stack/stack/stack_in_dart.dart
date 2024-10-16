class StackNode<T> {
  T data;

  StackNode<T>? below;

  StackNode(this.data);
}

class Stack<T> {
  StackNode<T>? top;

  int size;

  Stack()
      : top = null,
        size = 0;

  bool get isEmpty => top == null;

  T pop() {
    if (isEmpty) throw InvalidIndexError();
    var output = top!;
    top = top?.below;
    size--;

    return output.data;
  }

  T? peek() => top?.data;

  void push(T data) {
    var newNode = StackNode(data);
    if (isEmpty) {
      top = newNode;
    } else {
      newNode.below = top;
      top = newNode;
    }
    size++;
  }
}

class InvalidIndexError extends Error {
  @override
  String toString() => 'Invalid Index for this operation';
}

mixin BinaryHeapIndex {
  int parentOf(int idx) =>
      idx >= 0 ? ((idx - 1) / 2).truncate() : throw InvalidIndexError();

  int leftOf(int idx) => 2 * idx + 1;

  int rightOf(int idx) => 2 * idx + 2;
}

typedef Comparer<T> = bool Function(T parent, T child);

abstract class HeapBase<T> {
  bool get isEmpty;

  int get length;

  void insert(T item);

  void insertMany(List<T> items);

  void heapify(int rootIndex);

  T pop();

  T peek();
}
