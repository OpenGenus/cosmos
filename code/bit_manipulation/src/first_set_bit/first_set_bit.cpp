// Part of Cosmos (OpenGenus)
#include <bits/stdc++.h>
using namespace std;

int returnFirstSetBit(int n)
{
    if(n == 0)
        return 0;
    int position = 1;
    int m = 1;

    while (!(n & m))
    {
        m = m << 1;
        position++;
    }
    return (1 << (position - 1));
}

int main()
{
    int n;
    cin >> n;
    cout << returnFirstSetBit(n) << endl;

    return 0;
}
