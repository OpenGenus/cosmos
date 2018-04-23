/* Part of Cosmos by OpenGenus Foundation */

// Finding the Longest Increasing Subsequence using  Segment Tree


#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

// function to compare two pairs
int compare(pair<int, int> p1, pair<int, int> p2)
{

    if (p1.first == p2.first)
        return p1.second > p2.second;

    return p1.first < p2.first;
}

// Building the entire Segment tree, the root of which contains the length of the LIS
void buildTree(int* tree, int pos, int low, int high, int index, int val)
{

    if (index < low || index > high)
        return;

    if (low == high)
    {
        tree[pos] = val;
        return;
    }

    int mid = (high + low) / 2;

    buildTree(tree, 2 * pos + 1, low, mid, index, val);
    buildTree(tree, 2 * pos + 2, mid + 1, high, index, val);

    tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
}

// Function to query the Segment tree and return the value for a given range
int findMax(int* tree, int pos, int low, int high, int start, int end)
{

    if (low >= start && high <= end)
        return tree[pos];

    if (start > high || end < low)
        return 0;

    int mid = (high + low) / 2;

    return max(findMax(tree, 2 * pos + 1, low, mid, start, end),
               findMax(tree, 2 * pos + 2, mid + 1, high, start, end));
}

int findLIS(int arr[], int n)
{

    pair<int, int> p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].first = arr[i];
        p[i].second = i;
    }

    sort(p, p + n, compare);

    int len = pow(2, (int)(ceil(sqrt(n))) + 1) - 1;
    int tree[len];

    memset(tree, 0, sizeof(tree));

    for (int i = 0; i < n; i++)
        buildTree(tree, 0, 0, n - 1, p[i].second, findMax(tree, 0, 0, n - 1, 0, p[i].second) + 1);

    return tree[0];
}

int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of the LIS: " << findLIS(arr, n);
    return 0;
}


// Time Complexity: O(nlogn)
// Space Complexity: O(nlogn)
