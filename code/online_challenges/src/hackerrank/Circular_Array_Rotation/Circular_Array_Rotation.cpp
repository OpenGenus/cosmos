#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,q,i;
    cin>>n>>k>>q;
    vector<int> a(n);
    vector<int> b(n);
    for(i=0;i<n;i++)
    cin>>a[i];
        while(k>0)
    {
        a.insert(a.begin(),a.back());
        a.pop_back();
        k--;
    }
    for(i=0;i<q;i++)
    {
       int m;
        cin >> m;
    cout<<a[m]<<endl;
    }
    return 0;
}
