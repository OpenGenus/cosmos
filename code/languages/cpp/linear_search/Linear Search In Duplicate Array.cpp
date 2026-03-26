#include <iostream>
#include <vector>
using namespace std;

void linearSearch(const vector<int>& arr, vector<int>& result, int x)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == x)
        {
            result.push_back(i + 1); // store position (1-based)
        }
    }
}

int main()
{
    vector<int> arr = {2, 3, 4, 10, 40, 3, 10, 2, 10};
    int x = 10;

    vector<int> result;

    linearSearch(arr, result, x);

    if (result.empty())
    {
        cout << "Key not found";
    }
    else
    {
        cout << "Key found at position(s): ";
        for (int pos : result)
        {
            cout << pos << " ";
        }
    }

    return 0;
}
