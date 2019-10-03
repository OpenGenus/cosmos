#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Part of Cosmos by OpenGenus Foundation
void shellSort(vector<int> &ar)
{
    size_t j;
    for (size_t gap = ar.size() / 2; gap > 0; gap /= 2)
        for (size_t i = gap; i < ar.size(); i++)
        {
            int temp = ar[i];
            for (j = i; j >= gap && temp < ar[j - gap]; j -= gap)
                ar[j] = ar[j - gap];
            ar[j] = temp;
        }
}

int main()
{
    vector<int> inputArray;
    cout << "Enter the elements of the array: ";
    for (int i; cin >> i;)
        inputArray.push_back(i);
    shellSort(inputArray);
    for (size_t i = 0; i < inputArray.size(); i++)
        cout << inputArray[i] << " ";
    cout << endl;
    return 0;
}
