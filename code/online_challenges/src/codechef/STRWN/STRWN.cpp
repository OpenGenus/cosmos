#include <iostream>

#define ll long long
#define ld long double
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ff first
#define ss second
#define maxn 1000000007
#define PI 3.14159265358979323846

using namespace std; 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<fixed<<setprecision(20);
    ll a,b,c;
    cin>>a>>b>>c;
    if(a==0 && b==0 && c==0)
    {
        cout<<0<<endl;
        return 0;
    }
    if(a==0 && b==0 && c>0)
    {
        cout<<c<<endl;
        return 0;
    }
    if(a==0 && c==0 && b>0)
    {
        cout<<b<<endl;
        return 0;
    }
    if(c==0 && b==0 && a>0)
    {
        cout<<a<<endl;
        return 0;
    }
    if(a==0 && b>0 && c>0)
    {
        cout<<b<<endl;
        return 0;
    }
    if(b==0 && a>0 && c>0)
    {
        cout<<c<<endl;
        return 0;
    }
    if(c==0 && a>0 && b>0)
    {
        cout<<a<<endl;
        return 0;
    }
    cout<<1<<endl;
    return 0;
}
