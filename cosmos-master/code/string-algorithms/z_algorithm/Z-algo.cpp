#include <bits/stdc++.h>
using namespace std;
void Zalgo(string s,string pattern)
{
    string k=pattern + "&" + s;
	
    int Z[k.length()]; //Z-array for storing the length of the longest substring 
	                   //starting from s[i] which is also a prefix of s[0..n-1]
    int l=0,r=0;
    for(int i=1;i<k.length();i++)
    {
    	if(i>r)
    	{
    		l=i;r=i;
    		while(r<k.length() && k[r]==k[r-l])
    		  r++;
    		Z[i]=r-l;
    		r--;
    	}
    	else
    	{
    		int p=i-l;
    		if(Z[p] < r-i+1)
    		  Z[i]=Z[p];
    		else
    		 {
    		   l=i;
    		   while(r<k.length() && k[r]==k[r-l])
    		     r++;
    		   Z[i]=r-l;
    		   r--;	
    		 }
    	}
    }
    for(int i=1;i<k.length();i++)
    {
    	if(Z[i]==pattern.length())
    	{
    		cout<<"Found Pattern at "<<i-pattern.length()-1<<endl;
    	}
    }
}
int main() {
	 
	 string s="atababatggagabagt";//original string
	 string pattern="aba";//pattern to be searched in string
	 Zalgo(s,pattern);
	return 0;
}
/*Output:
Found Pattern at 2
Found Pattern at 4
Found Pattern at 12
*/