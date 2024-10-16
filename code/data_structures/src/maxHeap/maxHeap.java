public class MaxHeap {
    private int[] heap;
    private int currSize;
    private int capacity;

    public MaxHeap(int capacity) {
        this.heap = new int[capacity];
        this.currSize = 0;
        this.capacity = capacity;
    }

    private void heapifyAdd(int idx) {
        int root = (idx - 1) / 2;
        if(heap[idx] > heap[root]) {
            int temp = heap[root];
            heap[root] = heap[idx];
            heap[idx] = temp;
            heapifyAdd(root);
        }
    }

    private void heapifyRemove(int idx) {
        int max = idx;
        int leftIdx = idx * 2 + 1;
        int rightIdx = idx * 2 + 2;
        if(leftIdx < currSize && heap[leftIdx] > heap[idx]) {
            max = leftIdx;
        }
        if(rightIdx < currSize && heap[rightIdx] > heap[max]) {
            max = rightIdx;
        }
        if(max != idx) { // swap
            int temp = heap[max];
            heap[max] = heap[idx];
            heap[idx] = temp;
            heapifyRemove(max);
        }
    }

    public void insert(int itm) {
        if(currSize == capacity) {
            return;
        }
        heap[currSize] = itm;
        currSize++;
        heapifyAdd(currSize - 1);
    }

    public void remove() {
        if (currSize == 0) {
            return;
        }
        heap[0] = heap[currSize - 1];
        currSize--;
        heapifyRemove(0);
    }

    public void print() {
        for(int i = 0; i < currSize; i++) {
            System.out.print(heap[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        MaxHeap maxHeap = new MaxHeap(10);
        maxHeap.insert(3);
        maxHeap.insert(1);
        maxHeap.insert(6);
        maxHeap.insert(5);
        maxHeap.insert(9);
        maxHeap.insert(8);

        maxHeap.print(); // Expected output: 9 5 8 1 3 6

        maxHeap.remove();

        maxHeap.print(); // Expected output: 8 5 6 1 3
    }
}
