#include <vector>
#include <iostream>

using std::vector;
using std::endl;
using std::cin;
using std::cout;
/* 
 * Given an array of keys and their respective frequencies, we want the cost of the Optimal Binary Search Tree
 * The standard dynamic programming implementation will give us a solution with runtime complexity of O(n ^ 3)
 */

constexpr int infinity = 1e9;

int min(int a, int b){ return ( a < b ? a : b); }

int optimalSearchTree(const vector<int>& keys, const vector<int>& frequency, int totalNumberOfKeys) {
    vector< vector<int> > cost( totalNumberOfKeys, vector<int>(totalNumberOfKeys, 0) ); 

    vector<int> accumulatedFrequency(totalNumberOfKeys); // this vector will be used to store the prefix sum for the frequencies

    accumulatedFrequency[0] = frequency[0];

    for(int i = 1; i < totalNumberOfKeys; ++i) {
        accumulatedFrequency[i] = accumulatedFrequency[i-1] + frequency[i];
    }

    // Initializing the cost for unitary intervals
    for(int i = 0; i < totalNumberOfKeys; ++i) cost[i][i] = frequency[i];

    
    for(int length = 2; length <= totalNumberOfKeys; ++length) {
        for(int index = 0; index + length - 1 < totalNumberOfKeys; ++index) {
            int endIndex = index + length - 1;
            cost[index][endIndex] = infinity;

            for(int root = index; root <= endIndex; ++root) {
                int sumOfFrequencies = 0;
                if(index == 0) sumOfFrequencies = accumulatedFrequency[endIndex];
                else sumOfFrequencies = accumulatedFrequency[endIndex] - accumulatedFrequency[index - 1];
                int currentCost = sumOfFrequencies + cost[index][root-1];
                
                if(root + 1 < totalNumberOfKeys) currentCost += cost[root+1][endIndex];

                cost[index][endIndex] = min(cost[index][endIndex], currentCost);
            }
        }
    }
    return cost[0][totalNumberOfKeys-1];
}


int main() {
    int n;
    cout << "Please insert the number of keys on the Binary Search Tree: " << endl;
    cin >> n;
    vector<int> keys(n), freq(n);

    cout << "Please insert the " << n << " desired keys " << endl;
    for(int i = 0; i < n; ++i) cin >> keys[i];

    cout << "Please insert the " << n << " desired frequencies " << endl;
    for(int i = 0; i < n; ++i) cin >> freq[i];

    cout << "The cost of the Optimal Binary Search Tree = " << optimalSearchTree(keys, freq, n) << endl;

    return 0;
}
