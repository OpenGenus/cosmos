#include <bits/stdc++.h>

using namespace std;

long solve(long n) {
    long c = 0;
    while(n){
         c += n%2?0:1;
         n/=2; 
    }
    c=pow(2,c);
    return c;
}

int main() {
    long n;
    cin >> n;
    long result = solve(n);
    cout << result << endl;
    return 0;
}
