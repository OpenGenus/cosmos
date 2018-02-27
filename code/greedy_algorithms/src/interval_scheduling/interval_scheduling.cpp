#include<iostream>
#include<algorithm>
using namespace std;
// Part of Cosmos by OpenGenus Foundation
// A structure to represent a job
struct Job
{
    int jobNumber;    // Arbitrary number to represent a job
    int startTime;    // Start time of job
    int finishTime;    // Finish time of job
};

// This function is used for sorting all jobs according to Finish time
bool compare(Job a, Job b)
{
    return (a.finishTime < b.finishTime);
}

// Prints the order of the jobs to get the most efficiency where all jobs have "weight" 1
void printSchedule(Job arr[], int n)
{
    // Sort all jobs according to finish time
    sort(arr, arr+n, compare);

    Job result[n]; // To store result (Schedule)
    int resultSize = 0; // To store the size of result
    if (n != 0) // Check if the size sent in is 0, or else initialize the list.
    {
        result[0] = arr[0];
        resultSize = 1;
    }
    else
    {
        return;
    }

    // Iterate through all given jobs after the first since we know that we
    // take the smallest finish time job always (by greedy)
    for (int i=1; i<n; i++)
    {
       // Skip the job if it starts before the previous ends
       if (arr[i].startTime < result[resultSize - 1].finishTime)
       {
          continue;
       }
       else // Or else add it (by greedy)
       {
          result[resultSize] = arr[i];
          resultSize++;
       }
    }

    // Print the result
    for (int i=0; i<resultSize; i++)
        cout << result[i].jobNumber << " ";
    cout << endl;
}

int main()
{
    Job arr[] = { {1, 0, 5}, {2, 3, 9}, {3, 6, 25},
                   {4, 45, 120}, {5, 27, 31}};
    int n = 5;
    cout << "Here is the job Schedule:" << endl;
    printSchedule(arr, n);
    return 0;
}