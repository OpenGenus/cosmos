#include <iostream>
using namespace std;

int countNonConsecutiveOnes(int n)
{
    int endingZero[n], endingOne[n];
    endingZero[0] = endingOne[0] = 1;
    for (int i = 1; i < n; i++)
    {
        endingZero[i] = endingZero[i-1] + endingOne[i-1];
        endingOne[i] = endingZero[i-1];
    }
    return endingZero[n-1] + endingOne[n-1];
}
 
int main()
{
    int n;
    cout<<"\nEnter a number:";
    cin>>n;
    cout << countNonConsecutiveOnes(n) << endl;
    return 0;
}