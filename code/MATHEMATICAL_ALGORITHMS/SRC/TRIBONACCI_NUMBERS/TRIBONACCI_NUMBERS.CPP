/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>


using namespace std;

int main()
{
    int n, i;
    int a = 0, b = 1, c = 2, d;
    cout << "Enter a number\n";
    cin >> n;
    cout << a << " " << b << " " << c << " ";
    for (i = 0; i < n - 3; i++)
    {
        d = a + b + c;
        cout << d << " ";
        a = b;
        b = c;
        c = d;

    }
    return 0;
}
