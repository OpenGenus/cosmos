#include <iostream>
using namespace std;

class BloomFilter
{
public:
    BloomFilter(int size)
    {
        size_ = size;
        bits_ = new char[size_ / 8 + 1];
    }
    ~BloomFilter()
    {
        delete [] bits_;
    }

    void Add(int value)
    {
        int hash = value % size_;
        bits_[hash / 8] |= 1 << (hash % 8);
    }

    bool Contains(int value)
    {
        int hash = value % size_;
        return (bits_[hash / 8] & (1 << (hash % 8))) != 0;
    }

private:
    char* bits_;
    int size_;
};

int main()
{
    BloomFilter bloomFilter(1000);
    bloomFilter.Add(1);
    bloomFilter.Add(2);
    bloomFilter.Add(1001);
    bloomFilter.Add(1004);

    if (bloomFilter.Contains(1))
        cout << "bloomFilter contains 1" << endl;

    if (bloomFilter.Contains(2))
        cout << "bloomFilter contains 2" << endl;

    if (!bloomFilter.Contains(3))
        cout << "bloomFilter not contains 3" << endl;

    if (bloomFilter.Contains(4))
        cout << "bloomFilter not contains 4, but return false positive" << endl;
}
