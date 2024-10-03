// Part of Cosmos by OpenGenus Foundation

#include<iostream>
using namespace std;
 
unsigned long int catalan(unsigned int n)
{
    if (n <= 1) return 1;
 
    unsigned long int res = 0;
    for (int i=0; i<n; i++)
        res += catalan(i)*catalan(n-i-1);
 
    return res;
}
 
int main()
{
    for (int i=0; i<10; i++)
        cout << catalan(i) << " ";
    return 0;
}
