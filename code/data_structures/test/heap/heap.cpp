#include <iostream>
using namespace std;

class MaxHeap {
    int* heap;
    int size;
    int capacity;
public:
    MaxHeap(int cap) {
        size = 0;
        capacity = cap;
        heap = new int[cap];
    }

    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full\n";
            return;
        }
        int i = size++;
        heap[i] = value;

        while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    void extractMax() {
        if (size <= 0) {
            cout << "Heap is empty\n";
            return;
        }
        if (size == 1) {
            size--;
            return;
        }

        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapify(0);

        cout << "Max element: " << root << endl;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};
