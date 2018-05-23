#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    int decimal;
    cout << "Enter a decimal: ";
    cin >> decimal;

    stringstream hex;

    cout << "The number in hexadecimal: ";
    for (int i = 28; i >= 0; i -= 4)
    {
        int val = (decimal >> i) & 0xf;
        if (val > 9)
            hex << (char)('a' + (val - 10));
        else
            hex << val;
    }

    cout << hex.str() << endl;

    return 0;
}
