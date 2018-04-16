/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>
#include <vector>
using namespace std;

// Fenwick Tree (also known as Binary Indexed Tree or BIT)
class BIT
{
public:
    int n;
    vector<int> arr;

// constructor: initializes variables
    BIT(int n)
    {
        this->n = n;
        arr.resize(n + 1, 0);
    }

// returns least significant bit
    int lsb(int idx)
    {
        return idx & -idx;
    }

// updates the element at index idx by val
    void update(int idx, int val) // log(n) complexity
    {
        while (idx <= n)
        {
            arr[idx] += val;
            idx += lsb(idx);
        }
    }

// returns prefix sum from 1 to idx
    int prefix(int idx) // log(n) complexity
    {
        int sum = 0;
        while (idx > 0)
        {
            sum += arr[idx];
            idx -= lsb(idx);
        }
        return sum;
    }

// returns sum of elements between indices l and r
    int range_query(int l, int r) // log(n) complexity
    {
        return prefix(r) - prefix(l - 1);
    }

};

int main()
{
    vector<int> array = {1, 2, 3, 4, 5};
    int n = array.size();
    BIT tree(n);

    for (int i = 0; i < n; i++)
        tree.update(i + 1, array[i]);

    cout << "Range Sum from 2 to 4: " << tree.range_query(2, 4) << endl;
    cout << "Range Sum from 1 to 5: " << tree.range_query(1, 5) << endl;
}
