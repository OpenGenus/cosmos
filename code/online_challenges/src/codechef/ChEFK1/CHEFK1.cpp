#include<bits/stdc++.h>
using namespace std;
#define ll  long double
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,safe;
        cin>>n>>m;
        safe=m;
        ll check = (n*(n-1))/2+n;
        if(m==1&&n==2)
        {
            cout<<"1\n";
        }
        else if(n==1)
        {
            if(m==0)
                cout<<"0\n";
            else if(m==1)
                cout<<m<<endl;
            else
                cout<<"-1\n";
        }
        else
        {
            if(m>check||m<n-1)
            {
                cout<<"-1\n";

            }
            else
            {

                long long int count=0;
                m=m-n-1;
                count=2;
                if(m<=0)
                {
                    cout<<count<<endl;
                    continue;
                }
                else
                {
                    m=m-n+1;
                    count=3;
                    if(m<=0)
                    {
                        cout<<count<<endl;
                        continue;
                    }
                    else
                    {   m=safe;
                        m=m-n;
                        long double mod =(2*m)/n;
                      

                        long long int in =mod;
                       
                        if(mod>in)
                        {
                            count = int((2*m)/n) +1 ;
                        }
                        else
                            count = int((2*m)/n) ;

                        cout<<count+1<<"\n";


                    }


                }
            }


        }
    }
}
