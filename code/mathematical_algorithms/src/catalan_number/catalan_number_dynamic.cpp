#include <iostream>
using namespace std;
// Part of Cosmos by OpenGenus Foundation

int main()
{
    int n;
    cin >> n;				//input n

    long long cat[100000];
    cat[0] = 1;				//Initializing the values of first catalan number
    cout << cat[0];

    for (int i = 1; i <= n; i++)
    {
        cat[i] = 2 * (4 * i + 1) * cat[i - 1] / (i + 2);			//calculating nth catalan number
        cout << cat[i] << endl;
    }
}
