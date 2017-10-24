#include <iostream>
#include<vector>
using namespace std;

int countNonConsecutiveOnes(int n)
{
    vector<int> endingZero(n), endingOne(n);
    endingZero[0] = endingOne[0] = 1;
    for ( int i = 1; i < n; i++ )
    {
        endingZero[i] = endingZero[i-1] + endingOne[i-1];
        endingOne[i] = endingZero[i-1];
    }
    return endingZero[n-1] + endingOne[n-1];
}
 
int main()
{
    int decimalValue;
    cout<<"Enter a input decimal value: ";
    cin>>decimalValue;
    cout<<"\nCount of Binary representations of "<<decimalValue
    <<" not having consecutive ones = ";
    cout << countNonConsecutiveOnes(decimalValue) << endl;
    return 0;
}