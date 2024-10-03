#include <bits/stdc++.h>
using namespace std;

string strAdd(string s, string r){
	int re=0;
	string digit;
	if(r.length()<s.length()) r.insert(r.begin(),s.length()-r.length(),'0');
	else if(r.length()>s.length()) s.insert(s.begin(),r.length()-s.length(),'0');
	for(int i=s.length()-1; i>=0;--i){
		int a=(int(s[i]+r[i])+re-96);
		digit.insert(digit.begin(),char(a%10+48));
		re=a/10;
	}
	if(re!=0) digit.insert(digit.begin(),char(re+48));
	return digit;
}

int main(){   
	string s;
	string c;
	cout<<"Enter Number One"<<endl;
	cin>>s;
	cout<<"Enter Number Two"<<endl;
	cin>>c;
	cout<<"Addition Result: "<<strAdd(s,c)<<endl;
	return 0;
}