#include <iostream>
// Part of Cosmos by OpenGenus Foundation
using namespace std;
int power(int num, int exp)
{
    if (exp == 0)
        return 1;
    if (exp == 1)
        return num;
    int temp = power(num, exp / 2);
    temp *= temp;
    if (exp % 2 == 1)
        temp *= num;
    return temp;
}
int main()
{
    int num, exp;
    cout << "Input Number and Its Exponent" << endl;;
    cin >> num >> exp;
    cout << power(num, exp) << endl;
}
