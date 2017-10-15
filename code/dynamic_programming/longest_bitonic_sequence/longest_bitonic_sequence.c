/* Part of Cosmos by OpenGenus Foundation */

#include <stdio.h>

// helper function to get maximum of two integers
int max(int a, int b) {
    return a > b ? a : b;
}

/**
 *  Return the first element in v
 *  that is greater than or equal
 *  to x in O(lg n).
 */
int lower_bound(int v[], int n, int x) {
    
    int low = 0;
    int high = n;
    while(low < high) {
        int mid = (low + high) / 2;
        if(v[mid] >= x)
            high = mid;
        else
            low = mid + 1;
    } 
    return low;
}

/**
 *  Return the length of the longest
 *  bitonic sequence in v.
 *  Time complexity: O(n lg n).
 */
int longest_bitonic_sequence(int v[], int n) {
    
    int lis[n]; // stores the longest increasing sequence that ends at ith position
    int lds[n]; // strores the longest decreasing sequence that starts at ith position
    int tail[n], tailSize; // used to compute LIS and LDS
    int i;
    
    // Computing LIS
    tail[0] = v[0];
    tailSize = 1;
    lis[0] = 1;
    for(i = 1; i < n; ++i) {
        int idx = lower_bound(tail, tailSize, v[i]);
        if(idx == tailSize)
            tail[tailSize++] = v[i];
        else
            tail[idx] = v[i];
        lis[i] = tailSize;
    }

    // Computing LDS
    tailSize = 1;
    lds[n-1] = 1;
    for(int i = n-2; i >= 0; --i) {
        int idx = lower_bound(tail, tailSize, v[i]);
        if(idx == tailSize)
            tail[tailSize++] = v[i];
        else
            tail[idx] = v[i];
        lds[i] = tailSize;
    }

    // lis[i] + lds[i] - 1 is the length of the
    // longest bitonic sequence with max value
    // at position i.
    int ans = 0;
    for(int i = 0; i < n; ++i)
        ans = max(ans, lis[i] + lds[i] - 1);

    return ans;
}

int main() {
    
    int v1[] = {1, 2, 5, 3, 2};
    int v2[] = {1, 11, 2, 10, 4, 5, 2, 1};

    // Expected output: 5
    printf("%d\n", longest_bitonic_sequence(v1, sizeof(v1)/sizeof(v1[0])));
    //Expected output: 6 
    printf("%d\n", longest_bitonic_sequence(v2, sizeof(v2)/sizeof(v2[0])));

    return 0;
}
