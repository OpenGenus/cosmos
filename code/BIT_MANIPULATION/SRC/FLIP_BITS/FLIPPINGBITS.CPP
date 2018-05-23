#include <iostream>
// Part of Cosmos by OpenGenus Foundation
using namespace std;


int main()
{
    int T;
    unsigned int n;
    cin >> T;

    while (T--)
    {
        cin >> n;
        cout << ~n << endl;
    }
    return 0;
}
