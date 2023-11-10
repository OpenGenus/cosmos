#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
#define FLASH ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007

int main() 
{
	
	int t;
    long long k,n,ans,x,y,z,a;
    cin >> t;
    while(t--)
    {
       
       ans = x = y = z = a = 0;
       cin >> n >> k;
       k = k-1;
       x = (k/(n-1));
       y = (n%mod - 1%mod)%mod;
       
       if(x%2 == 0)
       {
           a = x/2;
           z = ((a%mod)*((x+1)%mod))%mod;
       }
       else
       {
           a = (x+1)/2;
           z = ((a%mod)*(x%mod))%mod;
       }

       ans = ((y%mod)*(z%mod))%mod;
       if(k % (n-1) != 0)
       {
           ans = ans + (k%(n-1))*(x+1);
       }
       
       cout << ans%mod << "\n";
    }
    
	return 0;
}