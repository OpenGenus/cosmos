/* 
* Algorithm : Running Median algorithm using Heaps
*
* Souce:  
* https://www.geeksforgeeks.org/median-of-stream-of-integers-running-integers/ 
*
* Problem : Given that integers are read from a data stream. 
* Find median of elements read so for in efficient way. 
* For simplicity assume there are no duplicates. For example, 
* let us consider the stream 5, 15, 1, 3 â€¦
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
#include <functional>
//sample

// Utility functions
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

class Heap 
{ 
    float A[1024]; // array of elements in heap with capacity of 1024 elements.
    int heapSize_; // Current number of elements in min heap
    std::function<bool(float, float)> comp;  //comparator function for min/max heap

public: 
    // Constructor 
    Heap(std::function<bool(float, float)> c) : comp(c){heapSize_ = 0;} 
 
    // Returns number of elements in heap
    int getCount() {return heapSize_;}
  
    // to heapify a subtree with the root at given index 
    void heapify(int idx) 
    { 
        int l = left(idx); 
        int r = right(idx); 
        int smallest = idx; 
        if (l < heapSize_ && comp(A[l], A[idx])) 
            smallest = l; 
        if (r < heapSize_ && comp(A[r], A[smallest])) 
            smallest = r; 
        if (smallest != idx) 
        { 
            std::swap(A[idx], A[smallest]); 
            heapify(smallest); 
        } 
    } 

    int parent(int idx) {return (idx-1)/2;} 

    // to get index of left child of node at index i 
    int left(int idx) {return (2*idx+ 1);} 

    // to get index of right child of node at index i 
    int right(int idx) {return (2*idx + 2);} 

    // to extract the root which is the min/max element 
    float extractTop() 
    {  
        if (heapSize_ == 1) 
        { 
            heapSize_--; 
            return A[0]; 
        } 

        // Store the return value, and remove it from heap 
        float root = A[0]; 
        A[0] = A[heapSize_-1]; 
        heapSize_--; 
        heapify(0); 
      
        return root; 
    } 

    // Returns the element (key at root) from heap 
    float getTop() {return A[0];} 
  
    // Inserts a new element 
    void insert(int currElement) 
    { 
        // First insert the new key at the end 
        heapSize_++; 
        int idx = heapSize_ - 1; 
        A[idx] = currElement; 

        // Fix the heap property if it is violated 
        while (idx != 0 && comp(A[idx], A[parent(idx)])) 
        { 
           std::swap(A[idx], A[parent(idx)]); 
           idx = parent(idx); 
        } 
    } 
}; 

// Function implementing algorithm to find median so far.
float getMedian(float currElement, float &median, Heap &left, Heap &right) 
{
    // Are heaps balanced? If yes, sig will be 0
    int sig = signum(left.getCount(), right.getCount()); 
    switch(sig)
    {
    case 1: // There are more elements in left (max) heap

        if (currElement < median) // current element fits in left (max) heap
        {
            // Remore top element from left heap and insert into right heap
            right.insert(left.extractTop());

            // current element fits in left (max) heap
            left.insert(currElement);
        }
        else
        {
            // current element fits in right (min) heap
            right.insert(currElement);
        }

        // Both heaps are balanced
        median = average(left.getTop(), right.getTop());

        break;

    case 0: // The left and right heaps contain same number of elements

        if (currElement < median) // current element fits in left (max) heap
        {
            left.insert(currElement);
            median = left.getTop();
        }
        else
        {
            // current element fits in right (min) heap
            right.insert(currElement);
            median = right.getTop();
        }

        break;

    case -1: // There are more elements in right (min) heap

        if (currElement < median) // current element fits in left (max) heap
            left.insert(currElement);
        else
        {
            // Remove top element from right heap and insert into left heap
            left.insert(right.extractTop());
            right.insert(currElement);
        }

        // Both heaps are balanced
        median = average(left.getTop(), right.getTop());

        break;
    }
  
    // No need to return, m already updated
    return median;
}

void printMedian(int A[], int size)
{
    float median = 0; // effective median
    //Max Heap
    Heap left = Heap([](float a, float b) -> bool{ return a > b;}); 
    //Min Heap
    Heap right = Heap([](float a, float b) -> bool{ return a < b;});

    for(int i = 0; i < size; i++)
    {
        median = getMedian(A[i], median, left, right);
        std::cout << median << std::endl;
    }
}

// Driver code
int main()
{

    int A[] = {5, 2, 1, 3, 2, 8, 7, 9, 2, 6, 2, 4};
    int size = sizeof(A)/sizeof(A[0]);

    // In lieu of A, we can also use data read from a stream
    printMedian(A, size);

    return 0;
}
