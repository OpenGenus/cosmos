#include <bits/stdc++.h>

using namespace std;

int Kadane(vector<int>& arr) {
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    for (int i = 0; i < arr.size(); i++) {
        max_ending_here = max_ending_here + arr[i];
        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
    }

    return max_so_far;
}

int main(){
    vector<int> a = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << Kadane(a) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)

// Kadane algorithm is a simple algorithm for finding the maximum subarray sum in a given array.