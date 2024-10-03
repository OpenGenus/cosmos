/* Part of Cosmos by OpenGenus Foundation */
#include<iostream>
#include <algorithm> 

int main(){
int t;
std::cin>>t;
while(t--){
    std::string s;
    std::cin>>s;
    if(s.size() == 1){
        std::cout << "DPS" << '\n';
        continue;
    }
    sort(s.begin(),s.end());
    int n= s.size();
    if(s.size()%2 != 0){
        int x=0;
        for(int i=0;i<n;){
            if(s[i] == s[i+1]){
            x++;
            i+=2;
            continue;
         }
        if(s[i] != s[i+1]){
            i++;
            continue;
        }
        }
        if(x >= (n-3)/2){
        std::cout << "DPS" << '\n';
        continue;
        }
    }
    if(s.size()%2 == 0){
            int x=0;
        for(int i=0;i<n;){
        if(s[i] == s[i+1]){
            x++;
            i+=2;
            continue;
        }
        if(s[i] != s[i+1]){
            i++;
            continue;
        }
        }
        if( x == (n-2)/2){
        std::cout << "DPS" << '\n';
        continue;
        }
    }
    std::cout << "!DPS" << '\n';
}
return 0;
}

