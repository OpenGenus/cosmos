#include <iostream>
using namespace std;

int main() {
	int t,x,y,n,i;
	char s[1000];
	cin>>t;
	while(t--)
	{
	    x=y=0;
	    cin>>n;
	    for(i=1;i<=n;++i)
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
	             y= y+1;
	         }
	         else if(s[i]=='D')
	         {
	             if(s[i]==s[i-1]||s[i-1]=='U')
	              continue;
	              y=y-1;
	         }
	     }
	     cout<<x<<" "<<y<<endl;
	     
	}
	return 0;
}
