#include<iostream>

using namespace std;

unsigned multiplyWith2(unsigned n) { //Since C++ 11 signed shift left of a negative int is undefined. 
    return (n << 1);                 //To avoid unexpected results always use unsigned when doing a multiply by 2 
}

int main(){
    cout << multiplyWith2(8) << endl;
    cout << multiplyWith2(15) << endl;

    return 0;
}