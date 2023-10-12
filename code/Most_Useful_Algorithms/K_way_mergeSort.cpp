#include <iostream>
#include <vector>
#include <climits>
#include <algorithm> 

using namespace std;

class KWayMerge {
public:
    vector<int> merge(vector<vector<int>>& arr) {
        int K = arr.size();

    
        int totalElements = 0;
        for (int i = 0; i < K; i++) {
            totalElements += arr[i].size();
        }

        vector<int> curPos(K, 0);
        vector<int> mergedArray(totalElements, 0);
        int p = 0;

        while (p < totalElements) {
            int minVal = INT_MAX;
            int minPos = -1;

            for (int i = 0; i < K; i++) {
                if (curPos[i] < arr[i].size()) {
                    if (arr[i][curPos[i]] < minVal) {
                        minVal = arr[i][curPos[i]];
                        minPos = i;
                    }
                }
            }

            curPos[minPos]++;
            mergedArray[p++] = minVal;
        }

        return mergedArray;
    }
};

int main() {
    cout << "K-Way Merge Sort Program" << endl;

    cout << "Enter the number of arrays (K): ";
    int K;
    cin >> K;

    vector<vector<int>> arr(K);

    cout << "Enter the arrays (elements can be in any order):" << endl;

    for (int i = 0; i < K; i++) {
        int N;
        cout << "Enter the number of elements in array " << i + 1 << ": ";
        cin >> N;
        arr[i].resize(N);

        cout << "Enter elements for array " << i + 1 << " (in any order): ";
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }

        
        sort(arr[i].begin(), arr[i].end());
    }

    KWayMerge kwm;

    vector<int> mergedArray = kwm.merge(arr);

    cout << "\nMerged Array (sorted): ";
    for (int i = 0; i < mergedArray.size(); i++) {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

    return 0;
}
