/* Part of Cosmos by OpenGenus Foundation */
#include <iostream>
#include <vector>
using namespace std;

//To print all subset sums
void printSums(int arr[], int n)
{
    long long total = 1 << n; //total = 2^n
    for (long long i = 0; i < total; i++) //We are iterating from 0 to 2^n-1
    {
        long long sum = 0;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                sum += arr[j];
        //Adding elements to set for which the bit is set
        cout << sum << " ";
    }
}

/*
 * We are not generating all subsets, but we are calculating all
 * subset sums based on all combinations of set bits
 * which can be obtained by iterating through 0 to 2^n-1
 */

//Driver code
int main()
{
    int arr[] = {4, 9, 3, 12, 6, 9};
    int n = sizeof(arr) / sizeof(int);
    printSums(arr, n);
    return 0;
}
