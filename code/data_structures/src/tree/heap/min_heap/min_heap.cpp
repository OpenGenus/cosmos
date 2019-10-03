/* Part of Cosmos by OpenGenus Foundation */
#include <iostream>
#include <vector>
using namespace std;

class minHeap {
    vector<int> v;

    void heapify(size_t i)
    {
        size_t l = 2 * i;
        size_t r = 2 * i + 1;
        size_t min = i;
        if (l < v.size() && v[l] < v[min])
            min = l;
        if (r < v.size() && v[r] < v[min])
            min = r;

        if (min != i)
        {
            swap(v[i], v[min]);
            heapify(min);
        }
    }

public:
    minHeap()
    {
        v.push_back(-1);
    }
    void insert(int data)
    {
        v.push_back(data);
        int i = v.size() - 1;
        int parent = i / 2;

        while (v[i] < v[parent] && i > 1)
        {
            swap(v[i], v[parent]);
            i = parent;
            parent = parent / 2;
        }

    }
    int top()
    {
        return v[1];
    }

    void pop()
    {

        int last = v.size() - 1;
        swap(v[1], v[last]);
        v.pop_back();
        heapify(1);
    }

    bool isEmpty()
    {
        return v.size() == 1;
    }

};

int main()
{

    int data;
    cout << "\nEnter data : ";
    cin >> data;
    minHeap h;
    while (data != -1)
    {
        h.insert(data);
        cout << "\nEnter data(-1 to exit) : ";
        cin >> data;
    }

    while (!h.isEmpty())
    {
        cout << h.top() << " ";
        h.pop();
    }
    return 0;
}
