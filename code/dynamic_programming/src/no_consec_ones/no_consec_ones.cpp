#include <iostream>
#include <vector>
using namespace std;

int countNonConsecutiveOnes(int n)
{
    vector<int> endingZero(n), endingOne(n);
    endingZero[0] = endingOne[0] = 1;
    for (int i = 1; i < n; i++)
    {
        endingZero[i] = endingZero[i - 1] + endingOne[i - 1];
        endingOne[i] = endingZero[i - 1];
    }
    return endingZero[n - 1] + endingOne[n - 1];
}

int main()
{
    int binaryStringLength;
    cout << "Enter the length of binary string: ";
    cin >> binaryStringLength;
    cout << "\nCount of Binary representations of length " << binaryStringLength
         << " not having consecutive ones = ";
    cout << countNonConsecutiveOnes(binaryStringLength) << endl;
    return 0;
}
