class Node {
  int priority;
  dynamic value;

  Node(this.priority, this.value);
}

class BinaryHeap {
  late List<Node> heap;

  BinaryHeap() {
    heap = [];
  }

  void insert(int priority, dynamic value) {
    final newNode = Node(priority, value);
    heap.add(newNode);
    _bubbleUp(heap.length - 1);
  }

  Node extractMin() {
    if (heap.isEmpty) {
      throw Exception("Heap is empty");
    }

    final min = heap[0];
    final last = heap.removeLast();
    if (heap.isNotEmpty) {
      heap[0] = last;
      _heapify(0);
    }

    return min;
  }

  void _bubbleUp(int index) {
    while (index > 0) {
      final parentIndex = (index - 1) ~/ 2;
      if (heap[index].priority < heap[parentIndex].priority) {
        // Swap the elements if the current element has higher priority than its parent.
        final temp = heap[index];
        heap[index] = heap[parentIndex];
        heap[parentIndex] = temp;
        index = parentIndex;
      } else {
        break;
      }
    }
  }

  void _heapify(int index) {
    final leftChild = 2 * index + 1;
    final rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < heap.length &&
        heap[leftChild].priority < heap[index].priority) {
      smallest = leftChild;
    }
    if (rightChild < heap.length &&
        heap[rightChild].priority < heap[smallest].priority) {
      smallest = rightChild;
    }

    if (smallest != index) {
      final temp = heap[index];
      heap[index] = heap[smallest];
      heap[smallest] = temp;
      _heapify(smallest);
    }
  }
}

void main() {
  final minHeap = BinaryHeap();

  minHeap.insert(4, "A");
  minHeap.insert(9, "B");
  minHeap.insert(2, "C");
  minHeap.insert(1, "D");
  minHeap.insert(7, "E");

  print("Extracted Min: ${minHeap.extractMin().value}"); // Should print "D"
  print("Extracted Min: ${minHeap.extractMin().value}"); // Should print "C"
  print("Extracted Min: ${minHeap.extractMin().value}"); // Should print "A"
}
