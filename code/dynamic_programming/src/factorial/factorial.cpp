// factorial of a number by using dynamic programming :D 

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int number=5;
    int result[100001]={0};
    result[0]=1;
    for(int i=1;i<=number;i++)
        result[i]=i*result[i-1];
    cout<<result[number]<<endl;
    return 0;
}
