#include <iostream>
using namespace std;

void xor_swap(int * a, int * b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main()
{
    int a = 10, b = 15;

    cout << "Before swapping: A = " << a << " and B = " << b << "\n";

    xor_swap(&a, &b);

    cout << "After swapping: A = " << a << " and B = " << b << "\n";

    return 0;
}
