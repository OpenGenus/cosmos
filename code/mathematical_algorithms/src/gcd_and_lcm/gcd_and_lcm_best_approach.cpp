
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios::sync_with_stdio(0);
ll gcd(ll a,ll b)
{
        while(a&&b)
        {
            if(a>b)
                a%=b;
            else
                b%=a;
        }
        return a+b;
}
ll lcm(ll a,ll b)
{
        return (max(a,b)/gcd(a,b))*min(a,b);
}
int main() 
{
        FIO;
        ll number_a, number_b;
        cin >> number_a >> number_b;
        answer = lcm(number_a,number_b);
        cout << answer;
        return 0;
}
