#include<bits/stdc++.h>
using namespace std;
/*
    Program to Find Root of the equation x*x*x-x-1=0 by False Position Method
    First we take 2 values from function of the Equation (negative/positive) then place it in a and b;
    then we check that if we assigned the right a and b
    then we apply False Position Formula
    then we iterate this similar way of bisection
*/

double func(double x)
{
    return x*x*x-x-1;
}

int main()
{
    int n=20,i;
    float a,b,x,y;
    cout<<"Here is The Equation : \n\n x*x*x-x-1=0 \n\n";
    cout<<"Enter Right Value for A and B : \n";
    cin>>a>>b;
    if (func(a) * func(b) >= 0)
    {
        cout << "You have not Assigned right A and B\n";
        return 0;
    }
    for(i=1;i<n;i++)
    {
        x=((a*func(b)-b*func(a))/(func(b)-func(a)));
        y=func(x);
        if(y==0)cout<<"Steps Taken "<<i<<"    X="<<x<<"\n";
        else if(y>0)
        {
            a=a;
            b=x;
            cout<<"Steps Taken "<<i<<"    X="<<x<<"\n";
        }
        else
        {
            a=x;
            b=b;
            cout<<"Steps Taken "<<i<<"    X="<<x<<"\n";
        }
    }

    return 0;
}


