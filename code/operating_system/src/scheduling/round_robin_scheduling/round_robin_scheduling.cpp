#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int flag = 0, timeQuantum;
    int n, remain;
    int waitTime = 0;
    cout << "Enter Total Process:\n";
    cin >> n;
    remain = n;
    vector<int> arrivalTime(n);
    vector<int> burstTime(n);
    vector<int> remainingTime(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Arrival Time and Burst Time for Process\n";
        cin >> arrivalTime[i];
        cin >> burstTime[i];
        remainingTime[i] = burstTime[i];
    }
    cout << "Enter Time Quantum:\n";
    cin >> timeQuantum;
    int turnaroundTime;
    for (int time = 0, count = 0; remain != 0;)
    {
        if (remainingTime[count] <= timeQuantum && remainingTime[count] > 0)
        {
            time += remainingTime[count];
            remainingTime[count] = 0;
            flag = 1;
        }
        else if (remainingTime[count] > 0)
        {
            remainingTime[count] -= timeQuantum;
            time += timeQuantum;
        }
        if (remainingTime[count] == 0 && flag == 1)
        {
            remain--;
            waitTime += time - arrivalTime[count] - burstTime[count];
            turnaroundTime += time - arrivalTime[count];
            flag = 0;
        }
        if (count == n - 1)
            count = 0;
        else if (arrivalTime[count + 1] <= time)
            count++;
        else
            count = 0;
    }
    cout << "\nAverage Waiting Time is " << waitTime * 1.0 / n;
    cout << "\nAvg Turnaround Time is " << turnaroundTime * 1.0 / n << "\n";
    return 0;
}
