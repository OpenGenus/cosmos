class BinaryHeap {
  List<int> _heap ;

  BinaryHeap() {
    _heap = [];
  }

  void insert(int value) {
    _heap.add(value);
    _heapifyUp();
  }

  int extractMin() {
    if (_heap.isEmpty) {
      throw Exception("Heap is empty");
    }

    final min = _heap[0];
    final last = _heap.removeLast();

    if (_heap.isNotEmpty) {
      _heap[0] = last;
      _heapifyDown();
    }

    return min;
  }

  void _heapifyUp() {
    int index = _heap.length - 1;

    while (index > 0) {
      final parentIndex = (index - 1) ~/ 2;
      if (_heap[index] < _heap[parentIndex]) {
        final temp = _heap[index];
        _heap[index] = _heap[parentIndex];
        _heap[parentIndex] = temp;
        index = parentIndex;
      } else {
        break;
      }
    }
  }

  void _heapifyDown() {
    int index = 0;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    while (leftChild < _heap.length) {
      int smallerChildIndex = leftChild;
      if (rightChild < _heap.length && _heap[rightChild] < _heap[leftChild]) {
        smallerChildIndex = rightChild;
      }

      if (_heap[index] <= _heap[smallerChildIndex]) {
        break;
      }

      final temp = _heap[index];
      _heap[index] = _heap[smallerChildIndex];
      _heap[smallerChildIndex] = temp;

      index = smallerChildIndex;
      leftChild = 2 * index + 1;
      rightChild = 2 * index + 2;
    }
  }

  bool isEmpty() {
    return _heap.isEmpty;
  }

  int size() {
    return _heap.length;
  }
}

void main() {
  final heap = BinaryHeap();

  heap.insert(5);
  heap.insert(10);
  heap.insert(3);
  heap.insert(7);

  print("Heap size: ${heap.size()}");

  while (!heap.isEmpty()) {
    print("Min element: ${heap.extractMin()}");
  }
}
