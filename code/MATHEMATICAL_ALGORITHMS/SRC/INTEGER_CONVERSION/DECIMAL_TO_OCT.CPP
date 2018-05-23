#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    int decimal;
    cout << "Enter a decimal: ";
    cin >> decimal;

    stringstream oct;

    cout << "The number in octal: ";
    // This fixes the grouping issue for the first set, which
    // only contains two bits.
    oct << (((decimal >> 30) & ~(1 << 2)) & 07);
    for (int i = 27; i >= 0; i -= 3)
        oct << ((decimal >> i) & 07);

    cout << oct.str() << endl;

    return 0;
}
