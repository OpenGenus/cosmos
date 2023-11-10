
#ifndef COSMOS_MAXHEAP_H
#define COSMOS_MAXHEAP_H
#include <iostream>


class maxHeap {

private :
    int* heap;
    int capacity;
    int currSize;
    void heapifyAdd(int idx);
    void heapifyRemove(int idx);

public:
    maxHeap(int capacity);
    void insert(int itm);
    void remove();
    void print();


};


#endif //COSMOS_MAXHEAP_H
