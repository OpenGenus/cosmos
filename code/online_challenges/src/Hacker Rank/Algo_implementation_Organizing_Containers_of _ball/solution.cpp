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
        vector <int> a(n);
        vector <int> b(n);
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                int temp;cin>>temp;
                a[j]=a[j]+temp;
                sum=sum+temp;
            }    
            b[i]=sum;
        }
            sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])
            {flag++;break;}
    }
    if(flag==0)
        cout<<"Possible"<<endl;
    else
        cout<<"Impossible"<<endl;
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

