#include <iostream>
using namespace std;

int main()
{
    int n, max, tmp;
    cout << "Enter the number of elements : ";
    cin >> n;
    cout << "Enter the numbers : \n";
    cin >> tmp;
    max = tmp;
    for (int i = 0; i < n - 1; ++i) {
        cin >> tmp;
        if (tmp > max) {
            max = tmp;
        }
    }
    cout << "The maximum value of your integers is" << max << "\n";
    return 0;
}
