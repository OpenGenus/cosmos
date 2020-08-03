//Part of Cosmos by OpenGenus Foundation

#include <iostream>
using namespace std;

int josephus(int n, int k)
{
    // Returns the safe position of n items
    // that have every kth item counted out
    // Note that the indice returned is zero-indexed
    if (n == 1)
        return 0;
    return (josephus(n - 1, k) + k) % n;
}

int main(void)
{
    int n, k;
    cout << "n: ";
    cin >> n;
    cout << "k: ";
    cin >> k;
    cout << "Safe position: " << josephus(n, k) << endl;

    return 0;
}
