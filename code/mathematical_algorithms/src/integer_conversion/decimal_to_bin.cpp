#include <iostream>
using namespace std;

int main()
{
    int decimal;
    cout << "Enter a decimal: ";
    cin >> decimal;

    cout << "The number in binary: ";
    for (int i = 31; i >= 0; i--)
        cout << ((decimal >> i) & 1);
    cout << endl;

    return 0;
}
