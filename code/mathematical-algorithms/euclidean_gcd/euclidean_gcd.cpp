#include<bits/stdc++.h>

using namespace std;

int steps=0;

int min(int x,int y){
    if(x>y){
        return x;
    }
    return y;
}

int gcd(int x,int y){
    if(x==0 && y==0){
        steps++;
        return -1;
    }

    if(x==0 || y==0){
        steps++;
        return x==0?y:y;
    }

    int smallerNum=min(x,y),divisor;
    for(int i=1;i<=smallerNum;i++){
        if(x%i==0 && y%i==0){
            divisor=i;
        }
        steps++;
    }

    return divisor;
}

int euclideanGCD(int x,int y){
    steps++;
    if(x==0 && y==0){
        return -1;
    }

    if(x==0){
        return y;
    }

    return euclideanGCD(y%x,x);
}

int main(){
    
    int a,b;
    cout<<"Enter 1st Number:";
    cin>>a;
    cout<<"Enter 2nd Number:";
    cin>>b;

    cout<<"GCD of "<<a<<" and "<<b<<" by Brute Force Approach is "<<gcd(a,b)<<"\n";
    cout<<"Steps Taken by Brute Force Approach: "<<steps<<"\n";
    steps=0;
    cout<<"GCD of "<<a<<" and "<<b<<" by Euclidean's Algorithm is "<<euclideanGCD(a,b)<<"\n";
    cout<<"Steps taken by Euclidean's Algorithm: "<<steps;
    return 0;
}