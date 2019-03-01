/* Binary Heap in C++ */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>


class BinaryHeap{

    private:
        std::vector <int> heap;
        int left(int parent);
        int right(int parent);
        int parent(int child);
        void heapifyup(int index);
        void heapifydown(int index);
    public:
        BinaryHeap()
        {}
        void Insert(int element);
        void DeleteMin();
        int ExtractMin();
        void DisplayHeap();
        int Size();
};

// Return Heap Size
int BinaryHeap::Size(){
    return heap.size();
}
 
// Insert Element into a Heap 
void BinaryHeap::Insert(int element){
    heap.push_back(element);
    heapifyup(heap.size() -1);
}

// Delete Minimum Element 
void BinaryHeap::DeleteMin(){
    
    if (heap.size() == 0){
        std::cout << "Heap is Empty"<< std::endl;
        return;
    }
    heap[0] = heap.at(heap.size() - 1);
    heap.pop_back();
    heapifydown(0);
    std::cout << "Element Deleted" << std::endl;
}
 
// Extract Minimum Element
int BinaryHeap::ExtractMin(){
    if (heap.size() == 0){
        return -1;
    }
    else
        return heap.front();
}
 
// Display Heap
void BinaryHeap::DisplayHeap(){
    std::vector <int>::iterator pos = heap.begin();

    std::cout << "Heap -->  ";
    while (pos != heap.end()){
        std::cout << *pos << " ";
        pos++;
    }
    std::cout << endl;
}
 
// Return Left Child
int BinaryHeap::left(int parent){
    int l = 2 * parent + 1;

    if (l < heap.size())
        return l;
    else
        return -1;
}
 
// Return Right Child
int BinaryHeap::right(int parent){
    int r = 2 * parent + 2;

    if (r < heap.size())
        return r;
    else
        return -1;
}
 
// Return Parent
int BinaryHeap::parent(int child){
    int p = (child - 1)/2;

    if (child == 0)
        return -1;
    else
        return p;
}
 
// Heapify- Maintain Heap Structure bottom up
void BinaryHeap::heapifyup(int in){
    if (in >= 0 && parent(in) >= 0 && heap[parent(in)] > heap[in]){
        int temp = heap[in];
        heap[in] = heap[parent(in)];
        heap[parent(in)] = temp;
        heapifyup(parent(in));
    }
}
 
// Heapify- Maintain Heap Structure top down
void BinaryHeap::heapifydown(int in){
 
    int child = left(in);
    int child1 = right(in);

    if (child >= 0 && child1 >= 0 && heap[child] > heap[child1]){
       child = child1;
    }
    if (child > 0 && heap[in] > heap[child]){
        int temp = heap[in];
        heap[in] = heap[child];
        heap[child] = temp;
        heapifydown(child);
    }
}

int main(){

    int choice, element;
    BinaryHeap h;
    while (1){
        std::cout << "------------------"<< std::endl;
        std::cout << "Operations on Heap"<< std::endl;
        std::cout << "------------------"<< std::endl;
        std::cout << "1.Insert Element"<< std::endl;
        std::cout << "2.Delete Minimum Element"<< std::endl;
        std::cout << "3.Extract Minimum Element"<< std::endl;
        std::cout << "4.Print Heap"<< std::endl;
        std::cout << "5.Exit"<< std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice){
        case 1:
            std::cout << "Enter the element to be inserted: ";
            std::cin >> element;
            h.Insert(element);
            break;
        case 2:
            h.DeleteMin();
            break;
        case 3:
            std::cout << "Minimum Element: ";
            if (h.ExtractMin() == -1){
                std::cout << "Heap is Empty" << std::endl;
            }
            else
                std::cout << "Minimum Element:  "<< h.ExtractMin() << std::endl;
            break;
        case 4:
            std::cout << "Displaying elements of Hwap:  ";
            h.DisplayHeap();
            break;
        case 5:
            exit(1);
        default:
            std::cout << "Enter Correct Choice" << std::endl;
        }
    }
    return 0;
}
