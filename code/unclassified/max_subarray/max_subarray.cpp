// This program prints the maximum contiguous subarray
// (subarray with max sum of elements)
// in a given array

#include <stdio.h>

using namespace std;

// 0: start, 1: end, 2: value

void max_crossing_subarray(int A[], int low, int high, int var[3]) {
    int mid = (low + high) / 2;
    int left_sum = 0, max_left_sum = -1e9;
    for (int i = mid; i>=low; i--) {
        left_sum += A[i];
        if (left_sum > max_left_sum) {
            max_left_sum = left_sum;
            var[0] = i;
        }
    }
    int right_sum = 0, max_right_sum = -1e9;
    for (int i = mid+1; i<=high; i++) {
        right_sum += A[i];
        if (right_sum > max_right_sum) {
            max_right_sum = right_sum;
            var[1] = i;
        }
    }
    var[2] = max_left_sum + max_right_sum;
}

void max_subarray(int A[], int low, int high, int var[3]) {
    if (low == high) {
        var[0] = low;
        var[1] = high;
        var[2] = A[low];
    } else {
        int mid = (high + low) / 2, left[3], right[3], cross[3];
        max_subarray(A, low, mid, left);
        max_subarray(A, mid+1, high, right);
        max_crossing_subarray(A, low, high, cross);
        if (left[2] >= right[2] && left[2] >= cross[2])
            var[0] = left[0], var[1] = left[1], var[2] = left[2];
        else if (right[2] >= left[2] && right[2] >= cross[2])
            var[0] = right[0], var[1] = right[1], var[2] = right[2];
        else
            var[0] = cross[0], var[1] = cross[1], var[2] = cross[2];
    }
}

int main() {

    int A[100], N;

    scanf("%d", &N);

    for (int i = 1; i<=N; i++)
        scanf("%d", &A[i]);

    int v[3] = {0, 0, 0};

    max_subarray(A, 1, N, v);

    printf("%d %d %d", v[0], v[1], v[2]);

}

