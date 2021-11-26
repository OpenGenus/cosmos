/*

// selection algorithms | quickselect stl | C++
// Part of Cosmos by OpenGenus Foundation

*/


#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int k;
    cin >> k;
    nth_element(v.begin(), v.begin() + k, v.end());
    cout << v[k] << endl;
    return 0;
}
