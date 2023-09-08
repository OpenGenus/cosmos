/*
* Part of Cosmos Organisation
* Author: RISHAV PANDEY.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string A(100,'0'),B;
    int i,n,t,j,x,l,N,m=0;
    cin >> N;
    for(i=0;i<N;++i)
    {
        cin >> B;
        reverse(B.begin(),B.end());
        l=B.length();
        t=0;
        for(j=0;j<l;++j)
        {
            x=int(A[j])-48+int(B[j])-48+t;
            A[j]=char((x%10)+48);
            t=x/10;
        }
        while(t!=0)
        {
            x=int(A[j])-48+t;
            A[j]=char((x%10)+48);
            t=x/10;
            ++j;
        }
        if (m<j-1)
            m=j-1;
    }
    for (i=m,j=1;i>=0&&j<=10;--i,++j)
        cout << A[i];
    return 0;
}