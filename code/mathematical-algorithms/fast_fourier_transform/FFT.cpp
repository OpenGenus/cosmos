#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ld                  long double
#define rep(i,n)            for(ll i=0;i<n;i++)
#define hell                1000000007LL
#define vi                  vector<ll>
#define vii                 vector< vi >
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pii                 pair<ll,ll>
#define all(c)              c.begin(),c.end()
#define sz(c)               c.size()
ld pi=2*asin(1);
complex<ld> iota(0.0,1.0);
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll power(ll x, ll y,ll p)
{
    ll res=1;
    x=x%p;
    while(y>0)
    {
        if(y&1)
            res=((res%p)*(x%p))%p;
        y=y>>1;
        x=((x%p)*(x%p))%p;
    }
    return res;
}
bool isprime(ll n)
{
    if(n<2) return false;
    else if(n==2) return true;
    else if(n%2==0) return false;
    else
    {
        ll z=sqrt(n);
        rep(i,z-1) if(n%(i+2)==0) return false;
        return true;
    }
}
vector<complex<ld> > fft(vi A,complex<ld> w)
{
    ll N=sz(A);
    if(N==1)
    {
        vector<complex<ld> > z;
        z.pb(complex<ld>(A[0],0));
        return z;
    }
    else
    {
        vi Ae,Ao;
        rep(i,N>>1) Ae.pb(A[2*i]);
        rep(i,N>>1) Ao.pb(A[2*i+1]);
        vector<complex<ld> > Aef=fft(Ae,w*w);
        vector<complex<ld> > Aof=fft(Ao,w*w);
        vector<complex<ld> > Af(N);
        complex<ld> temp(1,0);
        rep(i,N>>1)
        {
            Af[i]=Aef[i]+temp*Aof[i];
            Af[i+(N>>1)]=Aef[i]-temp*Aof[i];
            temp*=w;
        }
        return Af;
    }
}
vector<complex<ld> > ifft(vector<complex<ld> > A,complex<ld> w)
{
    ll N=sz(A);
    if(N==1) return A;
    else
    {
        vector<complex<ld> > Ae,Ao;
        rep(i,N>>1) Ae.pb(A[2*i]);
        rep(i,N>>1) Ao.pb(A[2*i+1]);
        vector<complex<ld> > Aef=ifft(Ae,w*w);
        vector<complex<ld> > Aof=ifft(Ao,w*w);
        vector<complex<ld> > Af(N);
        complex<ld> temp(1,0);
        rep(i,N>>1)
        {
            Af[i]=Aef[i]+temp*Aof[i];
            Af[i+(N>>1)]=Aef[i]-temp*Aof[i];
            temp*=w;
        }
        return Af;
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //n-1 and m-1 degree polynomials
    ll n,m;
    cin>>n>>m;
    vi A(n),B(m);
    rep(i,n) cin>>A[i];
    rep(i,m) cin>>B[i];
    ll in=0;
    while(sz(A)>(1<<in) || sz(B)>(1<<in)) in++;
    in++;
    while(sz(A)<(1<<in)) A.pb(0);
    while(sz(B)<(1<<in)) B.pb(0);
    ll N=sz(A);
    complex<ld> w(polar((ld)1.0,2*pi/N));
    vector<complex<ld> > Af=fft(A,w);
    vector<complex<ld> > Bf=fft(B,w);
    vector<complex<ld> > Cf(N);
    rep(i,N) Cf[i]=Af[i]*Bf[i];
    vector<complex<ld> > C=ifft(Cf,(ld)1/w);
    rep(i,N) C[i]=complex<ld>(real(C[i])/N,imag(C[i])/N);
    rep(i,N) cout<<C[i]<<" ";
    return 0;
}
