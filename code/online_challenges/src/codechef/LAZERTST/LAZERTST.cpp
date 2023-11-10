#include<iostream>

using namespace std;

typedef long long ll;

void solve()
{
    ll n,m,k,q;
    cin>>n>>m>>k>>q;
    vector<pair<int,int>> qs(q);
    vector<ll> ans(q,0);
    for (int i = 0; i < q; i++)
    {
        cin>>qs[i].first>>qs[i].second;
    }
    if(k==3)
    {
        cout<<2<<' ';
        for (int i = 0; i < q; i++)
        {
            cout<<m-1<<' ';
        }
        cout<<endl;
        int h;
        cin>>h;
        if(h==-1)
        {
            exit(1);
        }
    } 
    else if(k==100)
    {
        ll gm = 0;
        for (int i = 0; i < q; i++)
        {
            cout<<1<<' '<<qs[i].first<<' '<<qs[i].second<<' '<<(m*i)/10<<endl;
            ll h;
            cin>>h;
            if(h==-1)
            {
                exit(1);
            }
            gm = max(gm,h);
        }
        cout<<2<<' ';
        for (int i = 0; i < q; i++)
        {
            cout<<gm<<' ';
        }
        cout<<endl;
        int h;
        cin>>h;
        if(h==-1)
        {
            exit(1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
