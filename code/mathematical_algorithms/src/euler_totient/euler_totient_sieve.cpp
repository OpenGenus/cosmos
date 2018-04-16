#include <iostream>

using namespace std;
// Part of Cosmos by OpenGenus Foundation
const int MAXN = 1000000;
int phi[MAXN + 1];

// calculates euler phi(n) for n <= MAXN
void ETF_sieve()
{
    for (int i = 1; i <= MAXN; i++)
        phi[i] = i;

    for (int i = 2; i <= MAXN; i++)
    {
        if (phi[i] == i)
            for (int j = i; j <= MAXN; j += i)
            {
                phi[j] /= i;
                phi[j] *= (i - 1);
            }
    }
}

int main()
{
    ETF_sieve();
    int n;
    cin >> n;
    cout << phi[n] << endl;
    return 0;
}
