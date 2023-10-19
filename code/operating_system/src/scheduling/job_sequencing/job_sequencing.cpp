#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool jobComparator(const Job &a, const Job &b) {
    return a.profit > b.profit;
}

void jobSequence(vector<Job> &jobs) {
    int n = jobs.size();
    
    // Sort the jobs by profit in descending order.
    sort(jobs.begin(), jobs.end(), jobComparator);
    
    // Find the maximum deadline to determine the range for scheduling.
    int maxDeadline = 0;
    for (const Job &job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }
    
    // Initialize a boolean array to track job slots.
    vector<bool> slot(maxDeadline, false);
    
    // Initialize variables for the final sequence and total profit.
    vector<char> sequence;
    int totalProfit = 0;
    
    // Iterate through the sorted jobs and fill the slots if available.
    for (const Job &job : jobs) {
        for (int i = min(maxDeadline - 1, job.deadline - 1); i >= 0; i--) {
            if (!slot[i]) {
                slot[i] = true;
                sequence.push_back(job.id);
                totalProfit += job.profit;
                break;
            }
        }
    }
    
    // Print the final sequence and total profit.
    cout << "Job sequence: ";
    for (char jobId : sequence) {
        cout << jobId << " ";
    }
    cout << "\nTotal profit: " << totalProfit << endl;
}

int main() {
    vector<Job> jobs = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}
    };
    
    jobSequence(jobs);
    
    return 0;
}
