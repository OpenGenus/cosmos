#include <iostream>

long long int a[10000001];

int main() {
a[1]=1;
for(long long int i=2;i<=10000001;i++)
{
    if(i%2!=0)
    {
        a[i]=((i%1000000007)*(a[i-1]%1000000007))%1000000007;
    }
    else
    {
        a[i]=a[i-1];
    }
}

long long int t;
    std::cin>>t;
    while(t--)
        {
	    long long int n;
            std::cin>>n;
            std::cout<<a[n]<<std::endl;
        }
return 0;
}

