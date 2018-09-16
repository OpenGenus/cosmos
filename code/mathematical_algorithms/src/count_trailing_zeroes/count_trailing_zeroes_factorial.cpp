#include <iostream>
using namespace std;

int findTrailingZeros(int n)
{
    int count = 0;


    for (int i = 5; n / i >= 1; i *= 5)
        count += n / i;

    return count;
}

int main()
{
    int n = 100;
    cout << "Count of trailing 0s in " << 100 << "! is " << findTrailingZeros(n);
    return 0;
}
