#include <iostream>
using namespace std;
// Part of Cosmos by OpenGenus Foundation

int count_digits(int n)
{
    if (n == 0)
        return 1;

    int count = 0;
    while (n != 0)
    {
        count++;
        n /= 10;
    }

    return count;
}

int main()
{
    int n;
    cin >> n;

    cout << count_digits(n);

    return 0;
}
