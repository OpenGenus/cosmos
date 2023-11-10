#include <bits/stdc++.h>
using namespace std;
int binary_to_decimal(int number)
{
    int i, remainder, store, output;
    remainder = 1;
    store = 1;
    output = 0;
    for (i = 0; number > 0; i++)
    {
        remainder = number % 10;
        store = remainder * (pow(2, i));
        output = output + store;
        number = number / 10;
    }
    return output;
}
int main()
{
    int numberInput;
    cin >> numberInput;
    cout << binary_to_decimal(numberInput) << endl;
    return 0;
}
