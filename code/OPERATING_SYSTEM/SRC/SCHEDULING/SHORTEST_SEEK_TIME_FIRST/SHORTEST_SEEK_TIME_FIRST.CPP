#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of process: ";
    cin >> n;
    vector<int> burstTime(n);  // Array of burst times of processes
    cout << "Enter Burst time: \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Process[" << i + 1 << "]: ";
        cin >> burstTime[i];
    }
    sort(burstTime.begin(), burstTime.end()); // Sort the burst times
    vector<int> waitingTime(n);
    int total = 0;
    for (int i = 1; i < n; i++)
    {
        waitingTime[i] = 0;
        for (int j = 0; j < i; j++)
            waitingTime[i] += burstTime[j];
        total += waitingTime[i];
    }

    // Average waiting time = Total waiting time / no of processes
    int averageWaitingTime = (float)total / n;
    total = 0;
    vector<int> turnAroundTime(n);
    cout << "\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for (int i = 0; i < n; i++)
    {
        turnAroundTime[i] = burstTime[i] + waitingTime[i]; //Calculating Turnaround Time
        total += turnAroundTime[i];
        cout << "\np" << i + 1 << "\t\t" << burstTime[i] << "\t\t" << waitingTime[i] << "\t\t" <<
            turnAroundTime[i];
    }

    // Average Turnaround Time = total turn around time / no of processes
    int averageTurnAroundTime = (float)total / n;
    cout << "\nAverage Waiting Time: " << averageWaitingTime << "\n";
    cout << "Average Turnaround Time: " << averageTurnAroundTime << "\n";
    return 0;
}
