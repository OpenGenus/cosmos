#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter The Number for Factorial" << endl;
    cin >> n;
    vector<int> digit;
    digit.push_back(1);
    for (int j = 1; j < n + 1; j++)
    {
        int x = 0, y = 0;
        for (int i = digit.size() - 1; i >= 0; i--)
        {
            x = j * digit[i] + y;
            digit[i] = x % 10;
            y = x / 10;
        }
        while (y != 0)
        {
            digit.insert(digit.begin(), y % 10);
            y = y / 10;
        }
    }
    cout << "The Factorial is: " << endl;
    for (size_t i = 0; i < digit.size(); i++)
        cout << digit[i];
    cout << endl;
    return 0;
}
