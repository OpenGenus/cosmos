#include <iostream>
using namespace std;
// Part of Cosmos by OpenGenus Foundation
void printEgyptian(int numerator, int denominator)
{
    if (denominator == 0 || numerator == 0)
        return;

    if (denominator % numerator == 0)
    {
        cout << "1/" << denominator / numerator;
        return;
    }

    if (numerator % denominator == 0)
    {
        cout << numerator / denominator;
        return;
    }

    if (numerator > denominator)
    {
        cout << numerator / denominator << " + ";
        printEgyptian(numerator % denominator, denominator);
        return;
    }


    int n = denominator / numerator + 1;
    cout << "1/" << n << " + ";

    printEgyptian(numerator * n - denominator, denominator * n);
}

int main()
{
    int numerator, denominator;
    cin >> numerator >> denominator;
    cout << "Egyptian Fraction Representation of "
         << numerator << "/" << denominator << " is\n ";
    printEgyptian(numerator, denominator);
    return 0;
}
