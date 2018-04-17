#include <iostream>
// Part of Cosmos by OpenGenus Foundation
using namespace std;

long long int factorial(long long int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);

}

int main()
{
    long long int n;
    cin >> n;

    long long int result = factorial(n);
    cout << result << endl;
    return 0;
}
