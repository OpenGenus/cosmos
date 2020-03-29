#include <bits/stdc++.h>
#include<math.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while ( t -- ) {
        
        int n, x;
        long long int a, b, c, d, e, s;
        cin >> n;
        long long int ten = pow(10,n);
        cin >> a;
        cout << (2 * ten + a) << "\n";
        cout.flush();
        cin >> b;
        cout << ( ten - b ) << "\n";
        cout.flush();
        cin >> d;
        cout << ( ten - d ) << "\n";
        cout.flush();
        cin >> x;

        if(x == -1) return 0;
    }
    return 0;
}

