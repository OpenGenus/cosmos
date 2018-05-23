#include <iostream>
#include <vector>

// Part of Cosmos by OpenGenus Foundation
using namespace std;

#define N 10e7

vector<int> a(N + 1, 0);
void make_seive()
{

    for (int i = 2; i < N; i++)
        a[i] = i;
    for (int i = 4; i < N; i += 2)
        a[i] = 2;
    for (int i = 2; i * i < N; i++)
        if (a[i] == i)
            for (int j = i * i; j < N; j += i) // j=i*i because for j=i*2,i*3,i*4,i*5....,i*(i-1) we already
                                               // have a[j] = 2,3,4,5,6,7,......i-1 so that why we are starting
                                               // from i=i*i
                if (a[j] == j)
                    a[j] = i;

}

void print_prime_factors(int n)
{
    while (n != 1)
    {
        cout << a[n] << " ";
        n = n / a[n];
    }
}

int main()
{
    make_seive();
    int n;
    cin >> n;
    print_prime_factors(n);
    return 0;
}
