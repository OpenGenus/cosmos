#include <iostream>
using namespace std;

unsigned int russianPeasant(unsigned int a, unsigned int b)
{
    int res = 0;  // initialize result

    while (b > 0)
    {
        if (b & 1)
            res = res + a;
        a = a << 1;
        b = b >> 1;
    }
    return res;
}

int main()
{
    cout << russianPeasant(18, 1) << endl;
    cout << russianPeasant(20, 12) << endl;
    return 0;
}
