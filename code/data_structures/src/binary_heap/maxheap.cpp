#include <iostream>
using namespace std;

class maxHeap
{
	int* heap; 		//pointer for array
	int size;		//curent size
	int capacity;	//total capacity
	void heapifyUp(int index);
	void heapifyDown(int index);
	
	
	public:
	maxHeap(int capacity);
	void remove();
	void print();
	int getSize();
	int getMax();
	void insert(int val);
};

	
	maxHeap::maxHeap(int capacity)
	{
		heap = new int[capacity] {0};
		capacity = capacity;
		size = 0;
	}
	void maxHeap::heapifyUp(int index)
	{
		int parent = (index - 1) / 2;
		if (heap[index] > heap[parent])
		{
			std::swap(heap[index], heap[parent]);
			heapifyUp(parent);
		}
	}
	void maxHeap::heapifyDown(int index)
	{
		int largest = index;
		int rightChild = index * 2 + 2;
		int leftChild = index * 2 + 1;
		if (leftChild < size && heap[leftChild] > heap[rightChild])
			largest = leftChild;
		else if (rightChild < size && heap[rightChild] > heap[leftChild])
			largest = rightChild;
		if (largest != index)
		{
			std::swap(heap[index], heap[largest]);
			heapifyDown(heap[largest]);
		}			
	}
	void maxHeap::print()
	{
		for (int i = 0; i < size; i++) cout << heap[i] << endl;	
	}
	void maxHeap::remove()
	{
		if (size == 0) cout << "Heap is empty" << endl;
		else
		{
			heap[0] = heap[--size];
			heapifyDown(0);
		}
	}
	void maxHeap::insert(int val)
	{
		heap[size] = val;
		size++;
		heapifyUp(size - 1);
	}
	int maxHeap::getMax() {return heap[0];}
	int maxHeap::getSize() {return size;}

int main()
{
	int operation;
	int capacity;
	cout << "heap capacity: ";
	cin >> capacity;
	maxHeap maxHeap(capacity);
	while (operation != 6)
	{
		cout << "Operations" << endl;
		cout << "1. Insert" << endl;
		cout << "2. Delete Max" << endl;
		cout << "3. Display Max" << endl;
		cout << "4. Size" << endl;
		cout << "5. Print" << endl;
		cout << "6. Exit" << endl << endl;
		cout << "Enter operation number: ";
		cin >> operation;
		switch(operation)
		{
		case 1:
			if (maxHeap.getSize() >= capacity) cout << "Heap is full" << endl;
			else
			{
				int val;			
				cout << "Enter value to insert: " ;
				cin >> val;
				maxHeap.insert(val);
			}
			cout << endl;
			break;
		case 2:
			maxHeap.remove();
			cout << endl;
			break;
		case 3:
			cout << "Heap max element is: " << maxHeap.getMax() << endl;
			cout << endl;
			break;
		case 4:
			cout << "Heap size is: " << maxHeap.getSize() << endl;
			cout << endl;
			break;
		case 5:
			maxHeap.print();
			cout << endl;
			break;
		case 6:
			break;
		default:
			cout << "Invalid entry" << endl;
		}
	}
	return 0;
}