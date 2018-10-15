#include <iostream>
// Part of Cosmos by OpenGenus Foundation
using namespace std;

template<typename int_type>
int_type gcd(int_type i, int_type j)
{
    while (j != 0)
    {
        int_type x = i;
        i = j;
        j = x % j;
    }
    return i;
}

template<typename int_type>
bool isCoPrime(int_type i, int_type j)
{
    return gcd<int_type>(i, j) == 1;
}

int main()
{
    long long i, j;
    cout << "Enter two numbers : ";
    scanf("%lld %lld", &i, &j);
    cout << isCoPrime(i, j) << endl;
    return 0;
}
