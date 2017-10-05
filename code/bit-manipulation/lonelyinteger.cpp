#include <bits/stdc++.h>

using namespace std;

int lonelyinteger(vector <int> a) {
    int final = 0;
    for( int i=0 ; i< a.size() ; i++){
        final ^= a[i];
    }
    
    //Returns only number without a pair
    return final;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for(int a_i = 0 ; a_i < n ; a_i++){
       cin >> a[a_i];
    }
    
    //Finds the only number without a pair.
    int result = lonelyinteger(a);
    cout << result << endl;
    return 0;
}
