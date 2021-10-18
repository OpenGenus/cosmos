// To find the maximum subarray sum from the given array.
// This is a famous application for kedane algorithm.
/*
 *## kedane Algorithm:
 *
 * Initialize:
 *    max_sum = INT_MIN
 *    current_sum = 0
 *
 * Loop for each element of the array
 *  (a) current_sum = current_sum + a[i]
 *  (b) if(max_sum < current_sum)
 *            max_sum = current_sum
 *  (c) if(current_sum < 0)
 *             current_sum = 0
 * return max_sum
 */
//--------------------------------------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int size)
{ // kedane algorithm
    int max_sum = INT_MIN, current_sum = 0;

    for (int i = 0; i < size; i++)
    {
        current_sum = current_sum + a[i];
        if (max_sum < current_sum)
            max_sum = current_sum;

        if (current_sum < 0)
            current_sum = 0;
    }
    return max_sum;
}

// Driver program to test maxSubArraySum
int main()
{
    int a[] = {-2, -2, 5, -1, -3, 1, 7, -3};
    int n = sizeof(a) / sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}

/*---------------------------------------------------------------------------------------------------------------------------------------*/

// Time complexity: O(n)
// space complexity: O(1)
