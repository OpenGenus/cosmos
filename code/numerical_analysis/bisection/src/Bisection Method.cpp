#include<bits/stdc++.h>
using namespace std;
/*
    Program to Find Root of the equation x*x-2*x-2=0 by Bisection Method
    First we take 2 values from function of the Equation (negative/positive) then place it in a and b;
    then we check that if we assigned the right a and b
    then we apply Bisection Method Formula
    then we iterate it N'th Time
*/

double func(double x)
{
    return x*x-2*x-2;
}
int main()
{
    int n=20,i;
    float a,b,x,y;
     cout<<"Here is The Equation : \n\n x*x-2*x-2=0 \n\n";
    cout<<"Enter Right Value for A and B : \n";
    cin>>a>>b;
    if(func(a)<0 && func(b)>0)
    {
        for(i=1;i<n;i++)
    {
        x=(a+b)/2;
        y=(x*x-2*x-2);
        if(y==0)cout<<"Steps Taken "<<i<<"    x="<<x<<endl;
        else if(y>0)
        {
            a=a;
            b=x;
            cout<<"Steps Taken "<<i<<"    x="<<x<<endl;
        }
        else
        {
            a=x;
            b=b;
            cout<<"Steps Taken "<<i<<"    x="<<x<<endl;
        }
    }
    }
    else
    {
        cout << "You have not Assigned right A and B\n";
    }


    return 0;
}

