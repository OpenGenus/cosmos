#include <iostream>
#include <string.h>
using namespace std;
// Part of Cosmos by OpenGenus Foundation
string to_binary(int n)
{
    string binary = "";
    while (n > 0)
    {
        if ((n & 1) == 0)
            binary = '0' + binary;
        else
            binary = '1' + binary;

        n >>= 1;
    }
    return binary;
}

int to_number(string s)
{
    int number = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            number += (1 << (n - 1 - i));

    return number;
}

int main()
{
    //sample test
    string binary = to_binary(10);
    cout << binary << endl;

    int number = to_number("111");
    cout << number << endl;
    return 0;
}
