/*
    Trapezoidal method can be used to find integral of any function f(x)
    of form :

    I = integral(f(x) , where a < x < b)
    i.e. a and b are limits of integration.

    In this method we will have to divide the interval (a,b) into n equal parts.
    This will make the method more accurate.

    For this program I have take default values of a,b,and n. They
    can be modified during runtime.
    I have also taken an example function.

*/
#include<iostream>
#include<cmath>
using namespace std;

/*
    This is an example function. It can be modified as per requirement.

    f(x) = square_root( (x^2) + 1)
*/

double fn(double x)
{
    return sqrt(x*x + 1);
}

int a = 0; //lower limit of integration
int b = 1; // upper limit of integration
double n = 4; //number of interval, increasing n will increase accuracy

double  trap()
{
    double h = (b-a)/n;
    double ans = h/2;
    double sum = 0;
    for(int i=1;i<n;i++)
    {
        sum += fn(a + h*(i));
    }
    ans = ans*(fn(a)+fn(b)+2*sum);
    return ans;
}

int main()
{
    int inp=1;
    while(inp){
        cout<<"\n Enter 1 to integrate"<<endl<<"2 to change parameters"<<
            endl<<"0 to exit"<<endl;
        cin>>inp;
        if(!inp)break;
        switch(inp){
        case 1:
            cout<<trap();break;
        case 2:
            cout<<"a: ";cin>>a;
            cout<<"b: ";cin>>b;
            cout<<"n: ";cin>>n;
        }
    }

}
