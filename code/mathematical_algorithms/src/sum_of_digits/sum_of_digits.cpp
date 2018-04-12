//Part of Cosmos by OpenGenus Foundation
#include <iostream>

using namespace std;
long long int sum_of_digits(long long int n)
{
    long long int sum = 0;
    while (n != 0)
    {
        sum += n % 10; // summing the unit place digit of number n
        n /= 10;    // reducing the number by 10
    }
    return sum;  // returning the sum of digits of given number n
}

int main()
{
    long long int n;
    cin >> n;
    cout << sum_of_digits(n);

    return 0;
}
