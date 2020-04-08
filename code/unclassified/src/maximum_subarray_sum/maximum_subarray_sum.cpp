// Part of Cosmos by OpenGenus Foundation


// C++ implementation of simple algorithm to find
// Maximum Subarray Sum in a given array
// this implementation is done using Kadane's Algorithm which has a time complexity of O(n)

#include <iostream>
#include <vector>
#include <climits>

int maxSubarraySum(const std::vector<int>& arr)
{
    int maxSumSoFar = INT_MIN;
    int currMax = 0;
    for (int element : arr)
    {
        currMax += element;
        if (maxSumSoFar < currMax)
            maxSumSoFar = currMax;
        if (currMax < 0) // if the current maximum sum becomes less than 0 then we make it 0 to represent an empty subarray
            currMax = 0;
    }
    return maxSumSoFar;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;
        v[i] = x;
    }
    int answer = maxSubarraySum(v);
    std::cout << "Maximum subarray sum is " << answer << '\n';
    return 0;
}
