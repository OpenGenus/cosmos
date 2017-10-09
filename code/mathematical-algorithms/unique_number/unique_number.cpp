#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter a number:";
    int a;
    int b=0;;
    cin>>a;
    int c;
    c=a;
    while(a>0)// loop to reverse the number
    {
        b=b*10;
        b=b+a%10;//b is getting multiplied by 10 and is adding reminder through a each time
        a=a/10;//a is getting divided by 10 and quotient is stored again in a
    }
   if((b-c)==198)
    {
        cout<<"\nThe number is unique";
    }
    else
    {
        cout<<"\n not unique number";
    }
    return 0;
}
