#include<iostream>
using namespace std;
int main()
{
    long long int num,dup,rev=0;
    cout<<"Enter The Number\n";
    cin>>num;
    dup=num;
    while(num)
    {
        rev=(rev*10)+(num%10);
        num/=10;
    }
    if(rev==dup)
    cout<<"Yes,It Is a Palindrome Number";
    else
    cout<<"No,It Is not a Palindrome Number";
    return 0;
}
