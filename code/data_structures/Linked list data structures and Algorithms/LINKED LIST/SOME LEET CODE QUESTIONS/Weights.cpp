#include <iostream>
using namespace std;
int maximum(int w,int x,int y,int z){
    int mx1=max(w,x);
    int mx2=max(y,z);
    int mx=max(mx1,mx2);
    return mx;
}

void checker(int w,int x,int y,int z){
    int ans=maximum(w,x,y,z);
    for(int i=0;i<4;i++){
        if(w+x==ans || x+y==ans|| y+z==ans|| w+y==ans)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int w,x,y,z;
	    cin>>w>>x>>y>>z;
	    checker(w,x,y,z);
	    
	}
	return 0;
}
