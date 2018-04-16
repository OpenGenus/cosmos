#include <iostream>
// Part of Cosmos by OpenGenus Foundation
using namespace std;

int main()
{

    int n; cin >> n;

    int a = 1;

    while (n / a >= 1)
    {

        a = a * 10;

        int temp = n % a - n % (a / 10);

        temp = temp / (a / 10);

        int temp2;

        if (temp == 0)
        {

            temp2 = 5 * (a / 10);

            n = n - temp + temp2;
        }

    }

    cout << n << endl;
}
