#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout<<"...GCD and LCM of numbers..."<<endl;
    int a,b;
    cout<<"Enter two numbers: "<<endl;
    cin>>a>>b;
    int gcd,lcm;
    gcd=__gcd(a,b);
    lcm=(a*b)/gcd;
    cout<<"The GCD of the two numbers is: "<<gcd<<endl;
    cout<<"The LCM of the two numbers is: "<<lcm;
    return 0;
}
