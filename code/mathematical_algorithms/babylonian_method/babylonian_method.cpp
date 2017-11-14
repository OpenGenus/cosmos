#include<iostream>
using namespace std;

float squareRoot(int x){

    float i = x;
    float e = 0.000001;
    while(i - (x/i) > e){
        i = (i + (x/i))/2;
    }
    return i;
}

int main(){
    int x;
    cin>>x;
    cout<<"Square root of "<< x << " is " << squareRoot(x);
    return 0;
}
