#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// Round Robin implementation
// Returns the selected server name. 'index' is updated to point to the next server.
string round_robin(const vector<string>& servers, int& index) {
    if (servers.empty()) return "<no-server>";
    string server = servers[index];
    index = (index + 1) % servers.size();
    return server;
}

// Least Connections implementation (min-heap of (connections, server_index))
// Returns the server index with least connections (or -1 if none).
int least_connections(const priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& minHeap) {
    if (minHeap.empty()) return -1;
    return minHeap.top().second;
}

int main() {
    vector<string> servers = {"Server1", "Server2", "Server3"};
    int idx = 0;

    // Demonstrate round-robin selection and show the index after selection
    cout << "Round Robin selection 1: " << round_robin(servers, idx) << " | index = " << idx << endl;
    cout << "Round Robin selection 2: " << round_robin(servers, idx) << " | index = " << idx << endl;
    cout << "Round Robin selection 3: " << round_robin(servers, idx) << " | index = " << idx << endl;
    cout << "Round Robin selection 4: " << round_robin(servers, idx) << " | index = " << idx << endl;

    // Least connections: using a min-heap of (connection_count, server_index)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({3, 0});
    minHeap.push({1, 1});
    minHeap.push({5, 2});

    int leastIdx = least_connections(minHeap);
    if (leastIdx >= 0) {
        cout << "Least Connections → Server index: " << leastIdx
             << " (" << servers[leastIdx] << ")" << endl;
    } else {
        cout << "Least Connections → no servers available" << endl;
    }

    return 0;
}
