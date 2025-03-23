#include<iostream>
// Part of Cosmos by OpenGenus Foundation
using namespace std;

int main(){
    float res=1;
    int n=0;

    float numerator=365;
    int denominator=365;

    float prob;
    cout<<"Enter probability: ";
    cin>>prob;
    while(res>(1-prob)){
        res*=(numerator/denominator);
        numerator--;
        n++;
        cout<<"Count is "<<n<<" and probability is "<<res<<endl;
    }

    return 0;
}
