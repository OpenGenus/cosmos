/*
 * Part of Cosmos by OpenGenus Foundation
 */

/*
 * Author: Visakh S
 * Github: visakhsuku
 * Input: The number of elements in an array, The element to be searched, An integer array.
 * Output: if found returns "found" else "not found", using the sentinel linear search algorithm.
 */

#include <iostream>
#include <vector>
using namespace std;
void sentinelLinearSearch(std::vector<int> v, int n, int x)
{
    int last, i = 0;
    last = v[n - 1];
    v[n - 1] = x;
    while (v[i] != x)
        i++;
    if (i < n - 1 || last == x)
        cout << "found";
    else
        cout << "not found";
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x, input;
    std::vector<int> v;
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
    {
        cin >> input;
        v.push_back(input);
    }
    sentinelLinearSearch(v, n, x);
    return 0;
}
