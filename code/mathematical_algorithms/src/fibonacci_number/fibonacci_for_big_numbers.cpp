
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    int n; cin >> n;

    vector<int > v;

    v.push_back(1);

    for (int i = 2; i <= n; i++)
    {

        for (auto it = v.begin(); it != v.end(); it++)
            *it *= i;

        for (size_t j = 0; j < v.size(); j++)
        {

            if (v[j] < 10)
                continue;

            if (j == v.size() - 1)
                v.push_back(0);

            v[j + 1] += v[j] / 10;

            v[j] %= 10;
        }
    }
    for (auto it = v.rbegin(); it != v.rend(); it++)
        cout << *it;

    return 0;
}
