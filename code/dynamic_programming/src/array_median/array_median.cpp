#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Function to calculate the median element of the vector
float median(vector<int> arr)
{
    int n = arr.size();
   
    // If the size of the vector is odd, then return (n/2)th element
    if (n % 2 != 0)
        return (float)arr[n / 2];
    
    // If the size of the vector is even, then return the average of ((n-1)/2)th and (n/2)th element
    return (float)(arr[(n - 1) / 2] + arr[n / 2]) / 2;
}

int main()
{
    int n;
    cout << "Enter size of the Array"; // taking size as input from user
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " integers";
    for (int i = 0; i < n; i++) // storing elements in vector
        cin >> arr[i];
    sort(arr.begin(), arr.end()); // sorting the vector
    cout << "Median= " << median(arr); // Printing the median element
    return 0;
}
