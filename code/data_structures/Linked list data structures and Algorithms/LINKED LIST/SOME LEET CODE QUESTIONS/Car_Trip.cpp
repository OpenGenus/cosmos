#include <iostream>
using namespace std;
int costneedstopay(int x){
   if(x<=300)return 3000;
   if(x>300)
   {
    
    return 10*x;
   }
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int x;
	    cin>>x;
	cout<<costneedstopay(x)<<endl;
	}
	return 0;
}
