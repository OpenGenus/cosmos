/*
 * Original Problem: https://www.hackerrank.com/challenges/kaprekar-numbers/problem
 *
 * Solution tested against https://oeis.org/A053816
 */

#include <iostream>

using namespace std;

void setup(int n, int &d, long long &res)
{
    res = 1;
    d = 0;
    while (n > 0)
    {
        res *= 10;
        n /= 10;
        d += 1;
    }
}

bool isKaprekarNumber(int n)
{
    int d;
    long long divisor; // 10^d
    setup(n, d, divisor);

    long long square = (long long) n * n;
    long long r = square % divisor; // last d digits
    long long l = square / divisor; // remaining digits

    return (r + l == n);
}

void kaprekarNumbers(int p, int q)
{
    bool validRange = false;
    for (int i = p; i <= q; ++i)
    {
        if (isKaprekarNumber(i))
        {
            cout << i << " ";
            validRange = validRange || true;
        }
    }
    if (!validRange)
        cout << "INVALID RANGE";
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
