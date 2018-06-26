#include <bits/stdc++.h>

using namespace std;
long a[400009];

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector < pair < int, int > > v;
    for(int a0 = 0; a0 < m; a0++){
        int a;
        int b;
        int k;
        cin >> a >> b >> k;
        v.push_back(make_pair(a, k));
        v.push_back(make_pair(b+1, -1 * k));
    }
    long mx = 0, sum = 0;
    sort(v.begin(), v.end());
    for(int i=0 ; i<2*m; i++) {
        sum += v[i].second;
        mx = max(mx, sum);
    }
        
    cout<<mx<<endl;
    return 0;
}
