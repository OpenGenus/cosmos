#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    bool ans = true;
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            ans = false;
            break;
        }
    }
    return ans;
}

int main()
{
    int max_primes = 0;
    int prod;
    for(int a = -999; a <= 999; a++)
    {
        for(int b = -1000; b <= 1000; b++)
        {
            int n = 0;
            while(n * n + a * n + b > 1 && isPrime(n * n + a * n + b))
            {
                n++;
            }
            if(n > max_primes)
            {
                max_primes = n;
                prod = a * b;
            }
        }
    }
    cout << prod;
}
