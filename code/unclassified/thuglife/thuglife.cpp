#include<bits/stdc++.h>
using namespace std;


int stoi(string &s){stringstream ss(s);int x;ss>>x;return x;}
char* s = "134 x 1 y 135 x 1 y 49 x 7 z 1 w 1 x 2 z 3 x 2 z 1 x 2 z 1 w 4 x 2 z 4 x 4 w 52 x 1 y 21 x 12 w 16 x 7 z 1 w 1 x 2 z 3 x 2 z 1 x 2 z 1 w 4 x 2 z 3 x 6 z 1 w 50 x 1 y 17 x 19 w 13 x 3 w 2 z 3 w 1 x 2 z 3 x 2 z 1 x 2 z 1 w 4 x 2 z 2 x 3 z 2 w 2 z 1 w 50 x 1 y 15 x 23 w 14 x 2 z 4 x 2 z 3 x 2 z 1 x 2 z 1 w 4 x 2 z 1 x 3 z 4 x 1 w 51 x 1 y 13 x 27 w 12 x 2 z 4 x 2 z 3 x 2 z 1 x 2 z 1 w 4 x 2 z 1 x 2 z 57 x 1 y 12 x 29 w 11 x 2 z 4 x 7 z 1 x 2 z 1 w 4 x 2 z 1 x 2 z 3 x 5 z 1 w 48 x 1 y 11 x 31 w 10 x 2 z 4 x 7 z 1 x 2 z 1 w 4 x 2 z 1 x 2 z 3 x 5 z 1 w 48 x 1 y 10 x 33 w 9 x 2 z 4 x 2 z 3 x 2 z 1 x 1 w 1 z 1 w 3 x 1 w 2 z 1 x 2 z 1 w 5 x 2 z 6 x 1 w 2 z 1 w 3 x 1 w 2 z 1 w 3 x 3 z 1 w 3 x 1 z 2 x 1 w 3 x 1 z 3 x 1 w 2 z 1 w 7 x 1 y 10 x 33 w 9 x 2 z 4 x 2 z 3 x 2 z 2 x 2 z 1 w 1 x 1 w 2 z 1 w 1 x 1 w 2 z 1 w 2 x 1 w 2 z 1 w 6 x 1 z 2 x 1 w 2 x 1 w 1 z 2 x 1 z 1 w 2 x 1 z 2 x 1 z 3 x 1 z 2 x 1 w 1 z 2 x 1 z 2 x 1 w 1 z 10 x 1 y 24 x 5 w 23 x 2 z 4 x 2 z 3 x 2 z 2 x 1 w 6 z 3 x 1 w 7 z 6 x 1 w 1 z 5 x 1 z 1 w 3 x 1 z 2 x 1 z 2 x 1 z 3 x 1 z 2 x 1 w 2 z 1 x 1 z 2 x 1 z 2 x 3 z 6 x 1 y 52 x 2 z 4 x 2 z 3 x 2 z 3 x 1 w 3 z 1 w 6 x 4 z 1 w 8 x 1 z 5 x 2 w 2 x 2 w 2 x 1 z 2 x 1 z 3 x 1 z 2 x 1 w 1 z 1 x 2 z 2 x 2 w 2 x 2 w 6 x 1 y 26 x 2 w 64 x 1 w 3 z 3 x 4 z 3 x 3 z 1 w 3 x 1 z 2 x 1 w 1 z 2 x 1 z 3 x 4 z 7 x 1 y 25 x 3 w 107 x 1 y 7 x 1 w 16 x 5 w 16 x 1 w 89 x 1 y 7 x 1 w 16 x 5 w 16 x 1 w 89 x 1 y 7 x 2 w 14 x 7 w 14 x 2 w 48 x 2 z 1 w 3 x 1 z 1 w 5 x 1 w 1 z 1 w 5 x 1 w 1 z 1 w 2 x 1 w 1 z 1 x 1 z 3 x 1 w 1 z 6 x 1 y 7 x 3 w 12 x 10 w 11 x 3 w 10 x 2 z 5 x 2 z 1 w 1 x 6 z 1 x 6 z 14 x 1 z 1 w 1 z 3 x 1 z 1 w 4 x 1 w 1 z 2 w 1 z 3 x 1 z 2 w 1 z 2 x 1 w 1 z 2 w 3 x 1 z 1 w 1 z 5 x 1 y 7 x 5 w 7 x 15 w 7 x 5 w 10 x 2 z 5 x 2 z 1 w 1 x 6 z 1 x 6 z 14 x 3 z 3 x 1 z 1 w 4 x 1 z 3 x 1 z 2 x 1 w 1 z 5 x 1 w 2 z 4 x 1 z 1 w 6 x 1 y 7 x 39 w 10 x 2 z 5 x 2 z 1 w 1 x 2 z 5 x 2 z 18 x 1 z 1 x 1 w 1 z 2 x 1 z 1 w 4 x 1 z 3 x 1 z 2 x 1 w 1 z 5 x 1 w 2 z 5 x 1 w 1 z 5 x 1 y 7 x 27 w 1 x 1 z 10 w 10 x 2 z 5 x 2 z 1 w 1 x 2 z 5 x 2 z 18 x 1 z 2 w 1 z 2 x 1 z 3 w 2 x 1 w 1 z 2 w 1 z 3 x 1 z 2 w 1 z 2 x 1 w 1 z 2 w 3 x 1 z 1 w 1 z 5 x 1 y 7 x 26 w 1 x 12 w 10 x 2 z 5 x 2 z 1 w 1 x 5 z 2 x 5 z 15 x 3 z 3 x 3 z 1 w 3 x 1 w 1 z 1 w 5 x 1 w 1 z 1 w 2 x 1 w 1 z 1 x 1 z 1 w 2 x 1 w 1 z 6 x 1 y 8 x 15 w 2 x 3 w 2 x 1 w 1 z 14 w 10 x 2 z 5 x 2 z 1 w 1 x 5 z 2 x 5 z 56 x 1 y 9 x 20 w 5 z 10 w 12 x 2 z 5 x 2 z 1 w 1 x 2 z 3 w 2 x 2 z 3 w 56 x 1 y 12 x 17 w 6 z 7 w 14 x 2 z 5 x 2 z 1 w 1 x 2 z 5 x 2 z 59 x 1 y 15 x 15 w 6 z 2 w 18 x 2 z 4 w 1 x 2 z 1 w 1 x 2 z 5 x 2 z 4 w 55 x 1 y 24 x 5 w 2 x 6 z 19 x 6 z 1 x 2 z 1 w 1 x 2 z 5 x 6 z 55 x 1 y 31 x 1 w 6 z 1 w 17 x 6 z 1 x 2 z 1 w 1 x 2 z 5 x 6 z 55 x 1 y 32 x 1 w 6 z 1 w 95 x 1 y 33 x 1 w 6 z 1 w 94 x 1 y 34 x 1 w 6 z 1 w 93 x 1 y 36 x 6 z 1 w 92 x 1 y 37 x 1 w 4 z 1 w 92 x 1 y 38 x 3 z 1 w 93 x 1 y 39 x 2 w 94 x 1 y 132 x";
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
