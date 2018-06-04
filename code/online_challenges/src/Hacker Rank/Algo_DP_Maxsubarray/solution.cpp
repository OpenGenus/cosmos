#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> arr(n);
        int flag=0;
        for(int i=0;i<n;i++)
            {
            cin>>arr[i];
            if(arr[i]>=0)
                flag++;
            }
        if(flag==0)
        {
            sort(arr.begin(),arr.end());
            cout<<arr[n-1]<<" "<<arr[n-1]<<endl;
            continue;
        }
        
        int sum,ans,ans1;
        sum=ans=ans1=0;
        for(int i=0;i<n;i++)
        {
            if(sum+arr[i]>0)
                sum=sum+arr[i];
            else
                sum=0;
            if(arr[i]>=0)
                ans1=ans1+arr[i];
            
            ans=max(ans,sum);
            
        }
        
        
        cout<<ans<<" "<<ans1<<endl;
        
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

