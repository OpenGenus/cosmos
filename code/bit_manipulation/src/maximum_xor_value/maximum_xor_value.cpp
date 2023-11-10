#include <iostream>
using namespace std;

int maxXor(int l, int r)
{
    int num = l ^ r, max = 0;
    while (num > 0)
    {
        max <<= 1;
        max |= 1;
        num >>= 1;
    }
    return max;
}

int main()
{
    int res, _l, _r;

    cin >> _l;
    cin >> _r;

    res = maxXor(_l, _r);
    cout << res;

    return 0;
}
