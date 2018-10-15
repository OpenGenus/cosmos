#include <iostream>

using namespace std;

int main()
{
    int num, sum = 0, i;

    cout << "ENTER A NUMBER: ";
    cin >> num;

    for (i = 1; i < num; i++)
        if (num % i == 0)
            sum = sum + i;

    cout << "\n";

    if (sum == num)
        cout << num << " IS A PERFECT NUMBER\n";
    else
        cout << num << " IS NOT A PERFECT NUMBER\n";
    return 0;
}
