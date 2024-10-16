#include<bits/stdc++.h>
using namespace std;

/*

   Program to Find Root of the equation x*x*x-18=0 by Newton Rapson Method
   First we take 2 values from function of the Equation (negative/positive) then place it in x and y
   then we Differentiate This equation;
   then apply formula

*/
double func(double x)
{
    return x*x*x-18;
}

int main()
{
    int i;
    float a,b;
    cout<<"Here is The Equation : \n\n x*x*x-18=0 \n\n";
    cout<<"Enter Right Value for A and B : \n";
    cin>>a>>b;
    if(func(a)<0 && func(b)>0)
    {
        for(i=1; i<=10; i++)
        {
            float equation = ((a*a*a)-18);
            float differentiate = (3*(a*a));

            a-=equation/differentiate;

            cout<<"Steps Taken "<<i<<"    X="<<a<<endl;
        }
    }
    else
        cout<<"You have not Assigned right A and B\n";

    return 0;
}


