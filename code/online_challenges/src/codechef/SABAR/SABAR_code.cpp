/* Part of Cosmos by OpenGenus Foundation */
#include<iostream>

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
    int T;
    long long int a,b,c,d;
    std::cin>>T;
    while(T--) {
        std::cin>>a>>b;
        c=a+b-1;
        d=abs(a-b)+1;
        std::cout<<c<<" "<<d<<"\n";
    }
    return 0;
}

