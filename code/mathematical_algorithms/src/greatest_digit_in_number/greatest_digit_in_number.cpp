#include <iostream>
using namespace std;
int greatest_digit(int n)
{
    int max = 0;
    while (n != 0)
    {
        if (max < n % 10)
            max = n % 10;
        n /= 10;
    }
    return max;

}
int main()
{
    int n;
    cin >> n;
    cout << greatest_digit(n);
    return 0;
}
