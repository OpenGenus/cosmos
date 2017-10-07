

#include <iostream>
using namespace std;
int main() {
    cout<<"Enter a number"<<endl;
    int n, sum=0, digit;
    cin>>n;
    while (n>0){
        digit=n%10;
        n/=10;
        sum+=digit;
    }
    cout<<"The sum of the digits is "<<sum<<endl;
    return 0;
}
