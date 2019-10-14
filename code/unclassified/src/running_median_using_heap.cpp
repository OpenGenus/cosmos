/* 
* Algorithm : Running Median algorithm using Heaps
*
* Souce:  
* https://www.geeksforgeeks.org/median-of-stream-of-integers-running-integers/ 
*
* Problem : Given that integers are read from a data stream. 
* Find median of elements read so for in efficient way. 
* For simplicity assume there are no duplicates. For example, 
* let us consider the stream 5, 15, 1, 3 …
* 
* After reading 1st element of stream - 5 -> median - 5
* After reading 2nd element of stream - 5, 15 -> median - 10
* After reading 3rd element of stream - 5, 15, 1 -> median - 5
* After reading 4th element of stream - 5, 15, 1, 3 -> median - 4, so on...
* 
* when the input size is odd, we take the middle element of sorted data. 
* If the input size is even, we pick average of middle two elements in 
* sorted stream.
*
* Time Complexity: If we omit the way how stream was read, 
* complexity of median finding is O(N log N), as we need to read the stream, 
* and due to heap insertions/deletions.
*/

#include <iostream>

using namespace std;

// Heap capacity
#define MAX_HEAP_SIZE (128)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

// Utility functions

// exchange a and b
void exch(int &a, int &b)
{
    int aux = a;
    a = b;
    b = aux;
}

// greaterCompare and smaller are used as comparators
bool greaterCompare(int a, int b)
{
    return a > b;
}

bool smaller(int a, int b)
{
    return a < b;
}

float average(int a, int b)
{
    return (a + b) / 2.0;
}

/*
* Signum function
* = 0  if a == b  - heaps are balanced
* = -1 if a < b   - left contains less elements than right
* = 1  if a > b   - left contains more elements than right
*/
int signum(int a, int b)
{
    if (a == b)
        return 0;

    return a < b ? -1 : 1;
}

/*
* Heap implementation
* The functionality is embedded into Heap abstract class to avoid 
* code duplication
*/
class Heap
{

public:
    // Initializes heap array and comparator require in heapification
    Heap(int *b, bool (*c)(int, int)) : A(b), comp(c)
    { 
        heapSize = -1;
    }

    // Frees up dynamic memory
    virtual ~Heap()
    {
        if (A)
            delete[] A;
    }

    // We need only these four interfaces of Heap ADT
    virtual bool Insert(int key) = 0;
    virtual int  GetTop() = 0;
    virtual int  ExtractTop() = 0;
    virtual int  GetCount() = 0;

protected:

    // We are also using location 0 of array
    int left(int idx)
    {
        return 2 * idx + 1;
    }

    int right(int idx)
    {
        return 2 * (idx + 1);
    }

    int parent(int idx)
    {
        if (idx <= 0)
            return -1;

        return (idx - 1)/2;
    }

    // Heap array
    int *A;
    // Comparator
    bool (*comp)(int, int);
    // Heap size
    int heapSize;

    // Returns top element of heap data structure
    int top(void)
    {
        int max = -1;

        if (heapSize >= 0)
            max = A[0];

        return max;
    }

    // Returns number of elements in heap
    int count()
    {
        return heapSize + 1; 
    }

   /* 
    * Heapification
    * Note that, for the current median tracing problem we need to
    * heapify only towards root, always
    */

    void heapify(int idx)
    {
        int prt = parent(idx);

        /*
        * comp - differentiate MaxHeap and MinHeap
        * percolates up
        */
        if (prt >= 0 && comp(A[idx], A[prt]) )
        {
            exch(A[idx], A[prt]);
            heapify(prt);
        }
    }

    // Deletes root of heap
    int deleteTop()
    {
        int del = -1;

        if (heapSize > -1)
        {
            del = A[0];

            exch(A[0], A[heapSize]);
            heapSize--;
            heapify(parent(heapSize+1));
        }

        return del;
    }

    // Helper to insert key into Heap
    bool insertHelper(int key)
    {
        bool ret = false;

        if (heapSize < MAX_HEAP_SIZE)
        {
            ret = true;
            heapSize++;
            A[heapSize] = key;
            heapify(heapSize);
        }

        return ret;
    }
};

// Specilization of Heap to define MaxHeap
class MaxHeap : public Heap
{
private:

public:
    MaxHeap() : Heap(new int[MAX_HEAP_SIZE], &greaterCompare) {}

    ~MaxHeap() {}

    // Wrapper to return root of Max Heap
    int GetTop()
    {
        return top();
    }

    // Wrapper to delete and return root of Max Heap
    int ExtractTop()
    {
        return deleteTop();
    }
 
    // Wrapper to return # elements of Max Heap
    int  GetCount()
    {
        return count();
    }

    // Wrapper to insert into Max Heap
    bool Insert(int key)
    {
        return insertHelper(key);
    }
};

// Specilization of Heap to define MinHeap
class MinHeap : public Heap
{
private:

public:

    MinHeap() : Heap(new int[MAX_HEAP_SIZE], &smaller) {}

    ~MinHeap() {}

    // Wrapper to return root of Min Heap
    int GetTop()
    {
        return top();
    }

    // Wrapper to delete and return root of Min Heap
    int ExtractTop()
    {
        return deleteTop();
    }

    // Wrapper to return # elements of Min Heap
    int  GetCount()
    {
        return count();
    }

    // Wrapper to insert into Min Heap
    bool Insert(int key)
    {
        return insertHelper(key);
    }
};

// Function implementing algorithm to find median so far.
float getMedian(int currElement, float &median, Heap &left, Heap &right)
{
    // Are heaps balanced? If yes, sig will be 0
    int sig = signum(left.GetCount(), right.GetCount());
    switch(sig)
    {
    case 1: // There are more elements in left (max) heap

        if (currElement < median) // current element fits in left (max) heap
        {
            // Remore top element from left heap and insert into right heap
            right.Insert(left.ExtractTop());

            // current element fits in left (max) heap
            left.Insert(currElement);
        }
        else
        {
            // current element fits in right (min) heap
            right.Insert(currElement);
        }

        // Both heaps are balanced
        median = average(left.GetTop(), right.GetTop());

        break;

    case 0: // The left and right heaps contain same number of elements

        if (currElement < median) // current element fits in left (max) heap
        {
            left.Insert(currElement);
            median = left.GetTop();
        }
        else
        {
            // current element fits in right (min) heap
            right.Insert(currElement);
            median = right.GetTop();
        }

        break;

    case -1: // There are more elements in right (min) heap

        if (currElement < median) // current element fits in left (max) heap
            left.Insert(currElement);
        else
        {
            // Remove top element from right heap and insert into left heap
            left.Insert(right.ExtractTop());

            // current element fits in right (min) heap
            right.Insert(currElement);
        }

        // Both heaps are balanced
        median = average(left.GetTop(), right.GetTop());

        break;
    }
  
    // No need to return, m already updated
    return median;
}

void printMedian(int A[], int size)
{
    float median = 0; // effective median
    Heap *left  = new MaxHeap();
    Heap *right = new MinHeap();

    for(int i = 0; i < size; i++)
    {
        median = getMedian(A[i], median, *left, *right);

        cout << median << endl;
    }

    // C++ more flexible, ensure no leaks
    delete left;
    delete right;
}

// Driver code
int main()
{

    int A[] = {5, 2, 1, 3, 2, 8, 7, 9, 2, 6, 2, 4};
    int size = ARRAY_SIZE(A);

    // In lieu of A, we can also use data read from a stream
    printMedian(A, size);

    return 0;
}
