#include<bits/stdc++.h>

using namespace std;

int main() 
{
	
	int t,n,cnt,i,j;
	string s;
	cin >> t;
	while(t--)
	{
	    
	    cnt = 0;
	    cin >> n;
	    
	    int hash[n][26] = {0};
	    for(i = 0 ; i < n ; i++)
	    {
	        cin >> s;
	        for(j = 0 ; j < s.length() ; j++)
	        {
	            hash[i][s[j]-97]++;
	        }
	    }
	    
	    
	    for(i = 0 ; i < 26 ; i++)
	    {
	        for(j = 0 ; j < n ; j++)
	        {
	            if(hash[j][i] == 0)
	            {
	                cnt++;
	                break;
	            }
	        }
	    }
	    
	    cout << 26 - cnt << "\n";
	}
	return 0;
}