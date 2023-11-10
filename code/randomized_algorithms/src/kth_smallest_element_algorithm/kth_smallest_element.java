import java.util.*;
class Kth
{

class MinHeap
{
	int[] harr; 
	int capacity;
	int heap_size;

	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return ((2 * i )+ 1); }
	int right(int i) { return ((2 * i) + 2); }
	int getMin() { return harr[0]; }

	void replaceMax(int x)
	{
	this.harr[0] = x;
	minHeapify(0);
	}
	MinHeap(int a[], int size)
	{
	heap_size = size;
	harr = a; 
	int i = (heap_size - 1) / 2;
	while (i >= 0)
	{
		minHeapify(i);
		i--;
	}
	}


	int extractMin()
	{
	if (heap_size == 0)
		return Integer.MAX_VALUE;


	int root = harr[0];

	if (heap_size > 1)
	{
		harr[0] = harr[heap_size - 1];
		minHeapify(0);
	}
	heap_size--;
	return root;
	}

	void minHeapify(int i)
	{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		int t = harr[i];
		harr[i] = harr[smallest];
		harr[smallest] = t;
		minHeapify(smallest);
	}
	}
};

int kthSmallest(int arr[], int n, int k)
{

	MinHeap mh = new MinHeap(arr, n);


	for (int i = 0; i < k - 1; i++)
	mh.extractMin();


	return mh.getMin();
}


public static void main(String[] args)
{
	int arr[] = { 12, 3, 5, 7, 19 };
	int n = arr.length, k = 2;
	Kth kth = new Kth();
	System.out.print("K'th smallest element is " +
					kth.kthSmallest(arr, n, k));
}
}


