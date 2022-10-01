

#include "maxHeap.h"
using namespace std;
void maxHeap::heapifyAdd(int idx)
{
    int root = (idx-1)/2;
    if(heap[idx]>heap[root])
    {
        int temp = heap[root];
        heap[root] = heap[idx];
        heap[idx] = temp;
        heapifyAdd(root);
    }

}
void maxHeap::heapifyRemove(int idx)
{
    int max = idx;
    int leftIdx = idx*2+1;
    int rightIdx = idx*2+2;
    if(leftIdx<currSize&& heap[leftIdx]>heap[idx])
    {
        max=leftIdx;
    }
    if(rightIdx<currSize&& heap[rightIdx]>heap[max])
    {
        max=rightIdx;
    }
    if(max!=idx) // swap
    {
        int temp = heap[max];
        heap[max] = heap[idx];
        heap[idx] = temp;
        heapifyRemove(max);
    }

}
maxHeap::maxHeap(int capacity)
{
    heap = new int[capacity] ;
    currSize = 0;
    this->capacity = capacity;
}
void maxHeap::insert(int itm)
{
    if(currSize==capacity)
        return;
    heap[currSize] = itm;
    currSize++;
    heapifyAdd(currSize-1);
}
void maxHeap::remove()
{
    if (currSize==0)
        return;
    heap[0] = heap[currSize-1];
    currSize--;
    heapifyRemove(0);
}
void maxHeap::print()
{
    for(int i =0; i<currSize;i++)
    {
        cout<< heap[i];
    }
    cout<<endl;
}