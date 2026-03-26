// C++ code to linearly search x in arr[].
//If x is present then return its location, otherwise return -1

#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> arr, int x)
{
    int i;
    for (i = 0; i < arr.size(); i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// Driver's code
int main(void)
{
    vector<int> arr = { 2, 3, 4, 10, 40 };
    int x = 10;

    // Function call
    int result = linearSearch(arr, x);
    (result == -1)
    ? cout << "Element is not present in array"
           : cout << "Element is present at index " << result;
    return 0;
}

