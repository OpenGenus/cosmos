#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    ++n;
    vector<bool> primes(n, true);

    primes[0] = false;          // as 0 is not a prime
    primes[1] = false;          // as 1 is not a prime
    int k = 2;
    for (int i = 2; i < n; ++i)
    {
        while (primes[k] != true)
            k++;
        if (primes[i])
            for (int j = i; j < n; j = j + i)
                if (j != i)
                    primes[j] = false;

    }

    for (int i = 2; i < n; ++i)
        if (primes[i])
            cout << i << ' ';
    cout << '\n';
}
