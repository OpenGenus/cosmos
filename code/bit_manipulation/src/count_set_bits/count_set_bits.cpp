#include <iostream>
using namespace std;
// Part of Cosmos by OpenGenus Foundation
int count(int n)
{
    int c = 0;
    while (n)
    {
        c++;
        n &= (n - 1);
    }
    return c;
}

int main()
{

    int n;
    cin >> n;

    #ifdef BUILTIN
    cout << __builtin_popcount(n); // use builtin popcount
    #else
    cout << count(n);  // manual
    #endif

    return 0;
}
