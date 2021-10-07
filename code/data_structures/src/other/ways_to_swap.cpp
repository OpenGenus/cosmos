//HACKTOBERFEST 2021

//DIFFERENT WAYS TO SWAP 2 NUMBERS:-



#include<bits/stdc++.h>                     //it includes most of the headers files needed for basic programming
using namespace std;


int main()
{
    int a = 10, b = 5, temp;

    // 1. USING THIRD VARIABLE
    
    temp = a;
    a = b;
    b = temp;

    // 2. USING ADDITION AND SUBTRACTION

    a = a + b;
    b = a - b;
    a = a - b;

    // 3. USING MULTIPLICATION AND DIVISON

    a = a * b;
    b = a / b;
    a = a / b;

    // 4. USING BITWISE XOR OPERATOR

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout<<"after swapping a = "<<a<<" b = "<<b;

    
    //There are few more ways u can find by using the arithmetic operators 
    //differently or by using XOR in single line like this (a ^= b ^= a ^= b;) 
    //try on your and keep learning , good luck ! :)

    
    return 0;
}