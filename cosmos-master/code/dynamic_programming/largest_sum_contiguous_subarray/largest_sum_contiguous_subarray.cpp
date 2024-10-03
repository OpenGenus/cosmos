/*
BY:- https://github.com/alphaWizard

*/

#include <bits/stdc++.h>
using namespace std;
int maxsubarraysum(int ar[],int n)
{
int msf=ar[0],mth=ar[0];
int p=0;
if(ar[0]<0) ++p;
  int maxi=ar[0];
    for(int i=1;i<n;i++)
            {
        maxi=max(maxi,ar[i]); if(ar[i]<0) ++p;// for handing case of all negative array elements
       
            mth+=ar[i];
            if(mth>msf) msf=mth;
            if(mth<0) mth=0;
        }
return (p!=n)?msf:maxi;
}

int main() {
   int t;            // t number of test cases entered 
    cin>>t;
    while(t--)
        {
        int n;cin>>n;int ar[n];   //enter no, of terms
        for(int i=0;i<n;++i)
        cin>>ar[i];                //enter n elements of array
cout<<maxsubarraysum(ar,n)<<"\n";
    }
    return 0;
}
