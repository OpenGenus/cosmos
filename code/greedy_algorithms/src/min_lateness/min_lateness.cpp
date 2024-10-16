#include <bits/stdc++.h>
using namespace std;

class Request
{
  public:
    int deadline, p_time;
  bool operator < (const Request & x) const
  {
    return deadline < x.deadline;
  }
};
int main()
{
  int n, i, finish_time, start_time, min_lateness, temp;
  cout << "Enter the number of requests: ";
  cin >> n; // no. of requests 
  Request r[n];
  cout << "Enter the deadline and processing time of each request: ";
  for (i = 0; i < n; i++) // deadline and processing time of each job
    cin >> r[i].deadline >> r[i].p_time;
  sort(r, r + n); // sort jobs in increasing order of deadline
  start_time = 0;
  min_lateness = 0;
  for (i = 0; i < n; i++)
  {
    min_lateness = max((r[i].p_time + start_time) - r[i].deadline, min_lateness);
    start_time += r[i].p_time;
  }
  cout << "Maximum lateness of schedule: " <<  min_lateness;
  return 0;
}

