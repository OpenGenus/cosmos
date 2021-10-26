#include<iostream>

using namespace std;

int multiplyWith2(int n) {
    return (n << 1);
}

int main(){
    cout << multiplyWith2(8) << endl;
    cout << multiplyWith2(15) << endl;

    return 0;
}