
#include<bits/stdc++.h>
using namespace std;


int main()
{
    unsigned long int t;
    cin>>t;
    while(t--)
    {
        unsigned long int N,K,arr[26]={0},temp;
        int count1=0;
        char str[1000000];
        cin>>N>>K;
        cin>>str;
        temp=0;
        while(temp<N)
        {
            ++arr[str[temp]-97];
            ++temp;
        }
        for(int i=0;i<26;++i)
        {
            if(arr[i]%2!=0)
                ++count1;
            else if(arr[i]%2==0)
            {
                if(arr[i]/2>K)
                    ++count1;
            }
        }
        if(count1>0)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    
    
    }
    return 0;
}
