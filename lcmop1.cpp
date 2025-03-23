#include <iostream>  
using namespace std; 
class Lcmop 
{ 
public: int gcd(int a, int b)
 { 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
 } 
 
 int lcm(int a, int b)  
 {  
    return (a*b)/gcd(a, b);  
 }  
} ; 
int main()  
{  
    Lcmop l; 
    int a,b;
    cout<<"Enter a&b values:";
    cin>>a>>b;
    
    cout<<"LCM of "<<a<<" and "<<b<<" is "<<l.lcm(a, b);  
}  
//output:
//Enter a&b values:2 3
//LCM of 2 and 3 is 6
