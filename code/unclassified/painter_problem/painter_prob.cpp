#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool isPossible(int K, vector<int>& C, int minTime) {
    int curTime = 0;
    int curPainter = 1;

    for (int board = 0; board < C.size(); ++board) {
        if (C[board] > minTime) return false;

        if (curTime + C[board] <= minTime) {
            //allocate curBorad to the curPainter
            curTime += C[board];
            continue;
        }
        else if (C[board] <= minTime) {
            curTime = C[board];
            ++curPainter;   //allocated to a new painter
            if (curPainter > K) return false;
        }
    }
    return true;
}


int paint(int K, int T, vector<int> &C) {
    int high = accumulate(C.begin(), C.end(), 0);
    int low = 0;
    int ans = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(K, C, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ((ans * 1LL % 10000003) * (T * 1LL % 10000003)) % 10000003;
}

int main(){
    vector<int> C;
    int K;
    int L;
    cin >> K >> L;

    int sze;
    cin >> sze;
    for(int i = 0; i < sze; ++i){
        int x;
        cin >> x;
        C.push_back(x);
    }

    cout << paint(K, L, C);
}
