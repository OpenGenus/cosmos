// Part of Cosmos by OpenGenus Foundation
#include <iostream>
using namespace std;

typedef long long int lld;
bool IsSquare(lld number)
{
    lld min = 1;
    lld max = number;
    lld mid = min + (max - min) / 2;
    if (number == 0 || number == 1)
        return true;
    while (min < max)
    {
        if (mid * mid > number)
        {
            max = mid - 1;
            mid = min + (max - min) / 2;
        }
        else if (mid * mid < number)
        {
            min = mid + 1;
            mid = min + (max - min) / 2;

        }
        if (mid * mid == number)
            return true;

    }
    return false;
}

int main()
{

    int t;
    cout << "Enter the number of testcases:" << '\n';
    cin >> t;
    lld number;
    while (t--)
    {
        cin >> number;
        if (IsSquare(number))
            cout << "Natural Square number" << '\n';
        else
            cout << "Not a Natural Square" << '\n';
    }
    return 0;
}
