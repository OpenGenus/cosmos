#include<iostream> 
#include<algorithm> 
#include<vector> 
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int f=-1;
	    string s;
	    cin>>s;
	    int n=s.length();
	    
	    reverse(s.begin(),s.end());
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]=='1')
	        {
	            f=n-i-1;
	            break;
	        }
	    }
	    if(f=='-1')
	        cout<<-1;
	    else
	        cout<<f<<"\n";
	}
	return 0;
}
