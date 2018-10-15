#include <algorithm>
#include <iostream>

using namespace std;
// Part of Cosmos by OpenGenus Foundation
// A job has start time, finish time and profit.
struct Activitiy
{
    int start, finish;
};

// A utility function that is used for sorting
// activities according to finish time
bool activityCompare(Activitiy s1, Activitiy s2)
{
    return s1.finish < s2.finish;
}

// Returns count of maximum set of activities that can
// be done by a single person, one at a time.
void printMaxActivities(Activitiy arr[], int n)
{
    // Sort jobs according to finish time
    sort(arr, arr + n, activityCompare);

    cout << "Following activities are selected n";

    // The first activity always gets selected
    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";

    // Consider rest of the activities
    for (int j = 1; j < n; j++)
        // If this activity has start time greater than or
        // equal to the finish time of previously selected
        // activity, then select it
        if (arr[j].start >= arr[i].finish)
        {
            cout << "(" << arr[j].start << ", "
                 << arr[j].finish << "), ";
            i = j;
        }
}

int main()
{
    Activitiy arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},
                       {5, 7}, {8, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);
    printMaxActivities(arr, n);
    return 0;
}
