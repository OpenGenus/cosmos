#include <iostream>
using namespace std;
 
int main()
{
 
    long bin1, bin2;
    int i = 0, remainder = 0, sum[20];
 
    cout<<"Enter the first binary number: ";
    cin>>bin1;
    cout<<"Enter the second binary number: ";
    cin>>bin2;
    while (bin1 != 0 || bin2 != 0)
    {
        sum[i++] =(bin1 % 10 + bin2 % 10 + remainder) % 2;
        remainder =(bin1 % 10 + bin2 % 10 + remainder) / 2;
        bin1 = bin1 / 10;
        bin2 = bin2 / 10;
    }
    if (remainder != 0)
        sum[i++] = remainder;
    --i;
    cout<<"Sum of two binary numbers: ";
    while (i >= 0)
        cout<<sum[i--];
    return 0;
}

