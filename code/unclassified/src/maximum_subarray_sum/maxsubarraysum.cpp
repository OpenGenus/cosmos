// Part of Cosmos by OpenGenus Foundation


// C++ implementation of simple algorithm to find
// Maximum Subarray Sum in a given array
// this implementation is done using Kadane's Algorithm which has a time complexity of O(n)

#include <iostream>
#include <vector>
#include <climits>

int maxSubarraySum(std::vector<int> arr, int n)
{
    int maxSumSoFar = INT_MIN;
    int currMax = 0;
    for (int element : arr)
    {
        currMax = currMax + element;
        if (maxSumSoFar < currMax)
            maxSumSoFar = currMax;
        if (currMax < 0) // if the current maximum sum becomes less than 0 then we make it 0
            currMax = 0;
    }
    return maxSumSoFar;
}

int main()
{
    std::vector<int> v;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;
        v.push_back(x);
    }
    int answer = maxSubarraySum(v, n);
    std::cout << "Maximum subarray sum is " << answer << '\n';
    return 0;
}
