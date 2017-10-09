#include <iostream>

using namespace std;

inline int mx(int i, int j)
{
        return (i > j)? i : j;
}

int max_subarray_sum(int arr[], int length)
{
        int best = 0, sum = 0;

        for(int i = 0; i < length; ++i) {
                sum = mx(arr[i], sum + arr[i]);
                best = mx(best, sum);
        }

        return best;
}

int main()
{
        int array[] = {1, 0, -1, 3, -12, 4, 0, 1, -3};
        int n = 9;
        int best = max_subarray_sum(array, n);
        cout << best << endl;
        return 0;
}