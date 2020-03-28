#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
bool istrue(vector<int> a,vector<int> c) {
    pair<int, int> pairt[3];
    bool x = true;
    int i;
    for (i = 0; i < 3; ++i) {
        pairt[i].first = a[i];
        pairt[i].second = c[i];
    }
    sort(pairt, pairt + 3);
    for (i = 0; i < 2; ++i) {
        if (pairt[i].first == pairt[i + 1].first) {
            if (pairt[i].second != pairt[i + 1].second) {
                x = false;
                break;
            }
        }
        if (pairt[i].second > pairt[i + 1].second) {
            x = false;
            break;
        }
        if (pairt[i].second == pairt[i + 1].second) {
            if (pairt[i].first != pairt[i + 1].first) {
                x = false;
                break;
            }
        }
    }
    return x;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> a(3), c(3);
        int i;
        for (i = 0; i < 3; ++i) {
            cin >> a[i];
        }
        for (i = 0; i < 3; ++i) {
            cin >> c[i];
        }
        bool x = istrue(a, c);
        if (x) {
            cout << "FAIR" << endl;
        } else {
            cout << "NOT FAIR" << endl;
        }
    }
}
