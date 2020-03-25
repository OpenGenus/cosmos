#include<bits/stdc++.h>
using namespace std ;
#define lli long long int
unordered_map<lli,lli> mpp;
lli check(lli n)
{

  if(n==0)
    {  mpp[0]=0;
      return 0;
    }
  if(mpp[n]!=0)
      return mpp[n];
  else
      {
        mpp[n]=check(n/2)+check(n/3)+check(n/4);
        mpp[n]=max(n,mpp[n]);
        return mpp[n];
      }
}
int main()
{

 	lli  n;
 	while(cin>>n)
 	{
		lli d;
    d=check(n);

    cout<<max(n,d)<<"\n";
 	}
  return 0;

}
