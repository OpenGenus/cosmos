/* Part of Cosmos by OpenGenus Foundation */
/* Created by Shubham Prasad Singh on 12/10/2017 */

/* Check if a number is a power of 2 */
#include<iostream>
using namespace std;
typedef long long int int64;
bool isPowerOf2(int64 n)
{
    return n && (!(n & (n-1)));
}
int main()
{
    int64 n;
    cout<<"Enter a number\n";
    cin>>n;
    if(isPowerOf2(n))
        cout<<"Is a power of 2"<<endl;
    else
        cout<<"Not a power of 2"<<endl;
    return 0;
}

