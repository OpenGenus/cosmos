public class BinaryHeap {
    private int [] Heap;
    private int size;
    private int maxsize;
    private static final int front = 1;

    public BinaryHeap(int ms) {
        maxsize = ms;
        size = 0;
        Heap = new int[ms+1];
        Heap[0] = Integer.MIN_VALUE;
    }

    private int parent(int pos) {
        return pos/2;
    }

    private int leftChild(int pos) {
        return (2*pos);
    }

    private int rightChild(int pos) {
        return (2*pos)+1;
    }

    private boolean isLeaf(int pos) {
        if(pos >= (size/2) && pos <= size)
            return true;
        return false;
    }

    private void swap(int i, int j) {
        int t = Heap[i];
        Heap[i] = Heap[j];
        Heap[j] = t;
    }

    private void minHeapify(int pos) {
        if(!isLeaf(pos)) {
            if(Heap[pos] > Heap[leftChild(pos)] || Heap[pos] > Heap[rightChild(pos)]) {
                if(Heap[leftChild(pos)] < Heap[rightChild(pos)]) {
                    swap(pos,leftChild(pos));
                    minHeapify(leftChild(pos));
                }
                else {
                    swap(pos,rightChild(pos));
                    minHeapify(rightChild(pos));
                }
            }
        }
    }

    public void insert(int element) {
        if(size >= maxsize)
            return;
        Heap[++size] = element;
        int current = size;

        while (Heap[current] < Heap[parent(current)]) {
            swap(current, parent(current));
            current = parent(current);
        }
    }

    public void print()
    {
        for (int i = 1; i <= size / 2; i++) {
            System.out.print(" PARENT : " + Heap[i]
                    + " LEFT CHILD : " + Heap[2 * i]
                    + " RIGHT CHILD :" + Heap[2 * i + 1]);
            System.out.println();
        }
    }

    public void minHeap()
    {
        for (int pos = (size / 2); pos >= 1; pos--) {
            minHeapify(pos);
        }
    }

    public int remove()
    {
        int popped = Heap[front];
        Heap[front] = Heap[size--];
        minHeapify(front);
        return popped;
    }
}
