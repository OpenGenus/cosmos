/*
* Part of Cosmos Organisation
* Author: RISHAV PANDEY.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string func(long long int A)
    {
    switch(A)
        {
        case 0:return "";
        case 1:return "One";
        break;
        case 2:return "Two";
        break;
        case 3:return "Three";
        break;
        case 4:return "Four";
        break;
        case 5:return "Five";
        break;
        case 6:return "Six";
        break;
        case 7:return "Seven";
        break;
        case 8:return "Eight";
        break;
        case 9:return "Nine";
        break;
        case 10:return "Ten";
        break;
        case 11:return "Eleven";
        break;
        case 12:return "Twelve";
        break;
        case 13:return "Thirteen";
        break;
        case 14:return "Fourteen";
        break;
        case 15:return "Fifteen";
        break;
        case 16:return "Sixteen";
        break;
        case 17:return "Seventeen";
        break;
        case 18:return "Eighteen";
        break;
        case 19:return "Nineteen";
        break;
        case 20:return "Twenty";
        break;
        case 30:return "Thirty";
        break;
        case 40:return "Forty";
        break;
        case 50:return "Fifty";
        break;
        case 60:return "Sixty";
        break;
        case 70:return "Seventy";
        break;
        case 80:return "Eighty";
        break;
        case 90:return "Ninety";
        break;
    }
    return "yo";
}

string word(long long n)
    {
    string A="",t;
    long long temp=n%100;
    n/=100;
    if (temp<20)
        A=func(temp);
    else
        {
        A=func((temp/10)*10);
        if(temp%10)
            A=A+" "+func(temp%10);
    }
    if(!n)
        return A;
    temp=n%10;
    n/=10;
    if(temp)
        {
        A=func(temp)+" Hundred " + A;
    }
    if(!n)
        return A;
    temp=n%100;
    n/=100;
    if(temp)
        {
    if (temp<20)
        A=func(temp)+" Thousand "+A;
    else
        {
        t=func((temp/10)*10);
        if(temp%10)
            t+=" "+func(temp%10);
        A=t+" Thousand "+A;
    }
    }
    if(!n)
        return A;
    temp=n%10;
    n/=10;
    if(temp)
        {
        A=func(temp)+" Hundred " + A;
    }
    temp=n%100;
    n/=100;
    if(temp)
        {
    if (temp<20)
        A=func(temp)+" Million "+A;
    else
        {
        t=func((temp/10)*10);
        if(temp%10)
            t+=" "+func(temp%10);
        A=t+" Million "+A;
    }
    }
    if(!n)
        return A;
    temp=n%10;
    n/=10;
    if(temp)
        {
        A=func(temp)+" Hundred " + A;
    }
    if(!n)
        return A;
    temp=n%100;
    n/=100;
    if(temp)
        {
    if (temp<20)
        A=func(temp)+" Billion "+A;
    else
        {
        t=func((temp/10)*10);
        if(temp%10)
            t+=" "+func(temp%10);
        A=t+" Billion "+A;
    }
    }
    temp=n%10;
    n/=10;
    if(temp)
        {
        A=func(temp)+" Hundred " + A;
    }
    if(n)
        A=func(n)+ " Trillion "+A;
    return A;
}

int main() {
    long long t,n;
    cin>>t;
    while(t--)
        {
        cin>>n;
        cout<<word(n)<<endl;
    }
    return 0;
}