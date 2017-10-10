#include<bits/stdc++.h>
using namespace std;


int stoi(string &s){stringstream ss(s);int x;ss>>x;return x;}
stringstream thug(s);

void thugLife(){
	map<string,string> m;
	m["w"] = "+";	m["x"] = " ";m["y"] =  "\n"; m["z"] = "@";

	string temp,ch;
	while(thug>>temp){
			int cnt = stoi(temp);
			thug>>ch;
			while(cnt--){cout<<m[ch];}
    }
}

int main(){
thugLife();
return 0;
}
