/*
 * Part of Cosmos by OpenGenus Foundation
 * C++ program for weighted job scheduling using Dynamic Programming and Binary Search
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// A job has start time, finish time and profit.
//index  is used to store its given position as we will going to do sorting
struct Job
{
    int start, finish, profit, index;
};


// A utility function that is used for sorting events
// according to finish time
bool jobComparator(Job s1, Job s2)
{
    return s1.finish < s2.finish;
}

// A Binary Search based function to find the latest job
// (before current job) that doesn't conflict with current
// job. "index" is index of the current job. This function
// returns -1 if all jobs before index conflict with it. The
// array jobs[] is sorted in increasing order of finish time
int latestNonConflict(const vector<Job> &jobs, int index)
{
    // Initialize 'lo' and 'hi' for Binary Search
    int lo = 0, hi = index - 1;

    // Perform binary Search iteratively
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (jobs[mid].finish <= jobs[index].start)
        {
            if (jobs[mid + 1].finish <= jobs[index].start)
                lo = mid + 1;
            else
                return mid;
        }
        else
            hi = mid - 1;
    }

    return -11;             //-11 just a flag value but kept as same to that given to index 0 see: MaxProfit func
                            //so that backtracking can be done
}

// The main function that finds the subset of jobs
// associated with maximum profit such that no two
// jobs in the subset overlap.
void MaxProfit(vector<Job> &arr)
{

    int n = arr.size();
    // Sort jobs according to finish time
    sort(arr.begin(), arr.end(), jobComparator);           //reason for using index

    // Create an array to store solutions of subproblems.
    // DP[i] stores the Jobs involved and their total profit
    // till arr[i] (including arr[i])
    vector<int> DP(n + 2);

    // initialize DP[0] to arr[0]
    DP[0] = arr[0].profit;

    //contain what is the latest non conflicting job with the current job
    vector<int> nConflict;

    //no job non-conflicting with one job
    nConflict.push_back(-11);             //-11 is just a flag value

    for (int i = 1; i < n; i++)
        nConflict.push_back(latestNonConflict(arr, i));

    // Fill entries in DP[] using recursive property
    //recurrence
    for (int i = 1; i < n; i++)
    {
        int val = nConflict[i];
        DP[i] = max(DP[i - 1], DP[val] + arr[i].profit);
    }

    //finding jobs included in max profit
    int i = n - 1;
    cout << "Optimal jobs are -  ";
    while (true)
    {

        //terminating condition
        if (i < 0)                  //basically checking case of if it is equal to index of any job --(-11)
            break;

        //DP[i] will be one of the two values from which it is derived(shown above)

        if (i == 0)
        {
            cout << arr[i].index + 1;
            break;
        }
        else if (DP[i] == DP[i - 1])
            i--;

        else
        {
            cout << arr[i].index + 1 << " ";
            i = nConflict[i];
        }
    }

    cout << "\nMaximum Profit = " << DP[n - 1] << "\n";
}

int main()
{
    //example test case
    vector<Job> arr(4);
    arr[0] = {3, 5, 20, 0};
    arr[1] = {1, 2, 50, 1};
    arr[2] = {6, 19, 100, 2};
    arr[3] = {2, 100, 200, 3};

    MaxProfit(arr);

    return 0;
}
