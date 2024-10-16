#include<bits/stdc++.h>
using namespace std;

/*
   Program to Find Root of the equation x*x*x+x-5=0 by Iteration Method
   By simplified this equation we got eq=pow(5-x,(1/3)) then differentiate eq we got (-1/3*pow(5-x,(2/3)))
   then we checked if we put natural number in x, will it lower than 1 for all natural number? if no we can't
   apply iteration method else we can apply iteration method
*/

int main()
{
    float x=1;
    float eq=pow(5-x,(1/3));
    float diff=(-1/3*pow(5-x,(2/3)));
    int flag=0;
    cout<<" Here us The Equation : \n";
    cout<<" x*x*x+x-5=0 \n\n\n";
    while(x<100)
    {
        if((-1/3*pow(5-x,(2/3)))>1)
        {
            flag=1;
            break;
        }
        x++;
    }
    if(flag==1)
    {
        cout<<"Iteration Method Not Applicable in This Equation\n";
    }
    else
    {
        x=1;
        for(int i=1;i<=10;i++)
        {
            x=sqrt(1/x+1);

            cout<<"Step Taken "<<i<<"   X="<<x<<endl;
        }
    }
    return 0;
}

