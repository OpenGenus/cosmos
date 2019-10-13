#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        map<string,int> freq;
        
        int answer = 0;
        while(n--)
        {
            string s;
            cin >> s;
            
            freq[s]++;
            
            if(freq[s] == 2)
            answer++;
            if(freq[s] == 3)
            answer--;
        }
        cout << answer << endl;
    }
return 0;
}
