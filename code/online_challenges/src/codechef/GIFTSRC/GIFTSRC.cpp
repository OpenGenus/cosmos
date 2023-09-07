#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
	x=y=0;
	int n;
	cin>>n;
	char s[1000];
	for(int i=1;i<=n;++i)
	    cin>>s[i];
        s[0]='Z';
        for(i=1;i<=n;++i)
        {
            if(s[i]=='L')
	    {
	        if(s[i]==s[i-1]||s[i-1]=='R')
	            continue;
	        x=x-1;
	    }
	    else if(s[i]=='R')
	    {
	        if(s[i]==s[i-1]||s[i-1]=='L')
	            continue;
	        x=x+1;
	    }
	    else if(s[i]=='U')
	    {
	        if(s[i]==s[i-1]||s[i-1]=='D')
	            continue;
	        y=y+1;
	    }
	    else if(s[i]=='D')
	    {
	        if(s[i]==s[i-1]||s[i-1]=='U')
	            continue;
	        y=y-1;
	    }
	}    
        cout<<x<<" "<<y<<"\n";
	     
    }
	
    return 0;
}
