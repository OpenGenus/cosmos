#include <bits/stdc++.h>
using namespace std;

unsigned long int catalan_number(unsigned int n)
{
    // Base case
    if (n <= 1)
        return 1;
    vector<unsigned long int> catalan(n,0);
    catalan[0] = catalan[1] = 1;
    for (int i = 2; i <= n; i++) {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] = catalan[i] + catalan[j] * catalan[i - j - 1];
    }
    return catalan[n];
}
