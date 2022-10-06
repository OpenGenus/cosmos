#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number of Bits";
    cin >> n;
    int a[n];
    int b[n];
    int carry = 0;
    int result[n + 1];
    cout << "Enter the first number: ";
    // add numbers with space between digits.
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the second number: ";
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    for (int i = n-1; i >= 0; i--)
    {
        if (a[i] + b[i] + carry == 0)
        {
            result[i+1] = 0;
            carry = 0;
        }
        else if (a[i] + b[i] + carry == 1)
        {
            result[i+1] = 1;
            carry = 0;
        }
        else if (a[i] + b[i] + carry == 2)
        {
            result[i+1] = 0;
            carry = 1;
        }
        else if (a[i] + b[i] + carry > 2)
        {
            result[i+1] = 1;
            carry = 1;
        }
    }

    result[0]=carry;
    for(int i=0;i<=n;i++)
        cout<<result[i];
    return 0;
}
