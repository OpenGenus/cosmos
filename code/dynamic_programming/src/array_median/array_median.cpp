// Part of OpenGenus Cosmos
// A c++ program to find the array meedian
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

float median(vector<int> arr)
{
    int n = arr.size();
    //median of the array,if n=odd
    if (n % 2 != 0)
        return (float)arr[n / 2];
    //median of array,if n=even
    return (float)(arr[(n - 1) / 2] + arr[n / 2]) / 2;  
}

int main()
{
    int n;
    cout << "Enter size of the Array";
    cin >> n;   //input size of array
    vector<int> arr(n);
    cout << "Enter " << n << " integers";
    for (int i = 0; i < n; i++)
        cin >> arr[i];     //take input elements of array
    sort(arr.begin(), arr.end());
    cout << "Median= " << median(arr);   //printing the output
    return 0;
}
