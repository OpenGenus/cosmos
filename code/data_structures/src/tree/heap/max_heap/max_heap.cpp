/* Part of Cosmos by OpenGenus Foundation */
/*************************************************************************************
*   ░█▀▀░█▀▀░█▀█░█▀▀░█▀▄░▀█▀░█▀▀░░░█░█░█▀▀░█▀█░█▀█░░░█▀▀░▀█▀░█▀▄░█░█░█▀▀░▀█▀░█░█░█▀▄░█▀▀
*   ░█░█░█▀▀░█░█░█▀▀░█▀▄░░█░░█░░░░░█▀█░█▀▀░█▀█░█▀▀░░░▀▀█░░█░░█▀▄░█░█░█░░░░█░░█░█░█▀▄░█▀▀
*   ░▀▀▀░▀▀▀░▀░▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░░░▀░▀░▀▀▀░▀░▀░▀░░░░░▀▀▀░░▀░░▀░▀░▀▀▀░▀▀▀░░▀░░▀▀▀░▀░▀░▀▀▀
*
*   Generic heap structure implementation using vectors instead of arrays.
*   Holds instances of HeapElement class which consist of data,key pairs.
*   Can be initialized from existing array,vector or by inserting elements one by one.
*
*
*   Basic operations:
*     1.void insert(HeapElement<T> element):   Insert element to heap
*     2.HeapElement<T> deletemax():            Delete and return the maximum element from heap
*     3.HeapElement<T> peek_max():             Return max element without deleting it from heap
*     4.bool isEmpty():             Check if heap is Empty
*     5.HeapElement<T> getHeapSize():          Return heap size
*     6.void printHeap():           Print heap content
*************************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <iostream>
#include <climits>

using namespace std; //Not the best tactic, used for cleaner code and better understanding

template<typename P>
class HeapElement {
public:
    int key;
    P data;

    HeapElement()
    {
    }

    HeapElement(P datain, int keyin)
    {
        key = keyin;
        data = datain;
    }
};

template<typename T>
class Heap {
private:
    std::vector<HeapElement<T>> heap;
    int hpsz;
public:

    Heap()
    {
        hpsz = 0;   //At first the Heap is Empty
        HeapElement<T> init;
        heap.push_back(init);      //Index 0 must be initialized because we start indexing from 1
    }

    Heap(std::vector<HeapElement<T>>& array)
    {
        int n = array.size();
        HeapElement<T> init();
        heap.push_back(init);      //The first index of heap array is 1 so we must fill 0 index with dummy content
        heap.insert(heap.end(), array.begin(), array.end());
        hpsz = n;   //Heap size = Heap Array size
        for (int i = n / 2; i > 0; i--)
            combine(i);
    }

    void insert(HeapElement<T> elmnt)
    {
        heap.push_back(elmnt);
        hpsz++;
        int i = hpsz, parent = i / 2;
        while ((i > 1) && (heap[parent].key < heap[i].key))
        {
            iter_swap(heap.begin() + parent, heap.begin() + i);
            i = parent; parent = i / 2;
        }
    }

//Get max without deleting from heap
    int peek_max()
    {
        return heap[1].data;
    }

    void combine (int i)
    {
        int mp = i, left = 2 * i, right = (2 * i) + 1;
        if ((left <= hpsz) && (heap[left].key > heap[mp].key))
            mp = left;
        if ((right <= hpsz) && (heap[right].key > heap[mp].key))
            mp = right;
        if (mp != i)
        {
            iter_swap(heap.begin() + i, heap.begin() + mp);
            combine(mp);
        }
    }

    HeapElement<T> deletemax()
    {

        if (isEmpty())
        {
            HeapElement<T> error; return error;
        }
        HeapElement<T> max = heap[1];

        heap[1] = heap[hpsz--];
        combine(1);
        return max;
    }

    bool isEmpty()
    {
        return hpsz == 0;
    }

    int getHeapSize()
    {
        return hpsz;
    }

    void printHeap()
    {
        for (int i = 1; i <= hpsz; i++)
            std::cout << heap[i].data;
        printf("\n");
    }

};

int main()
{
    /*
     * Heap can be constructed using vector of HeapElement<T> as input
     * or array of HeapElement<T>
     */
    //HeapElement<T> a[] = {.......HeapElement<T> HERE,another HeapElement<T>.........};
    //vector<HeapElement<T>> heapin (a, a + sizeof(a) / sizeof(a[0]) ); //C++2003
    //std::vector<HeapElement<T>> heapin ({.......HeapElement<T> HERE,another HeapElement<T>.........}); //C++2011
    // std::vector<HeapElement<T>> heapin(std::begin(a), std::end(a));    //C++2003
    //Heap test(heapin);

    /*
     * Heap can be constructed using one by one insertion of elements
     * <-------------------------------------------------------------->
     * Heap<char> test;
     * HeapElement<char> one('A',1);
     * test.insert(one);
     *
     * HeapElement<char> two('B',3);
     * test.insert(two);
     *
     * HeapElement<char> three('C',2);
     * test.insert(three);
     *
     * HeapElement<char> four('D',5);
     * test.insert(four);
     *
     * test.printHeap(); //Heap array
     * }
     */

    Heap<char> test;


    int num_elements;
    std::cout << "Enter number of elements:";

    std::cin >> num_elements;
    HeapElement<char> elem;      //For example we create a heap that includes celements with char values and int keys

    while (num_elements != 0)
    {
        num_elements--;
        std::cout << "Enter element data:";
        std::cin >> elem.data;
        std::cout << "Enter element key:";
        std::cin >> elem.key;
        test.insert(elem);
        std::cout << "--------------" << '\n';
    }

    test.printHeap();     //Heap array


    while (!test.isEmpty())
        std::cout << "Max after delete: " << test.deletemax().data << '\n';
    return 0;
}
