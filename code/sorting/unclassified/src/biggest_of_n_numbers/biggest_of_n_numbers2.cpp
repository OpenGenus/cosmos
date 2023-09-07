#include <iostream>
using namespace std;

int main()
{
    int n, max, tmp;
    cout << "Enter numbers of elements : ";
    cin >> n;
    cout << "Enter numbers\n";
    cin >> tmp;
    max = tmp;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> tmp;
        if (max < tmp)
            max = tmp;
    }
    cout << "Maximum is " << max << "\n";
    return 0;
}
